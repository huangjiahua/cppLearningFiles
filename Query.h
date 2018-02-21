#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>


class QueryResult;
/*
** TextQuery
 */
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

/*
** QueryResult
 */
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
    std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

/*
** The base class Query_base
 */
class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

/*
** The interface class Query
 */
 class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const
        { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query): q(query) { }
    std::shared_ptr<Query_base> q;
 };

/*
** derived classes
 */
    /*
    ** class WordQuery
    ** A WordQuery looks for a given string
     */
class WordQuery: public Query_base {
private:
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { }
    QueryResult eval(const TextQuery &t) const override
        { return t.query(query_word); }
    std::string rep() const override { return query_word; }
    std::string query_word;
};

    /*
    ** class NotQuery
     */
class NotQuery: public Query_base {
private:
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }
    std::string rep() const override { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const override;
    Query query;
};

    /*
    ** class BinaryQuery
     */
class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), opSym(s) { }
    std::string rep() const override { return "(" + lhs.rep() + " "
        + opSym + " " + rhs.rep() + ")"; }
    Query lhs, rhs;
    std::string opSym;
};
        /*
        ** class derived from BinaryQuery
        ** class AndQuery
         */
class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const override;
};

        /*
        ** class OrQuery
         */
class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery&) const override;
};

/*
** member functions
 */
    /*
    ** member functions for class Query
     */
inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }

/*
** operators
 */

    /*
    ** operator << for Query
     */
std::ostream &
operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

    /*
    ** Query operator~(const Query &operand)
     */
inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

    /*
    ** Query operator&(const Query &, const Query &)
     */
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

    /*
    ** Query operator|(const Query &, const Query &)
     */
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

/*
** evals of the classes
 */
QueryResult
OrQuery::eval(const TextQuery& text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines =
        std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
AndQuery::eval(const TextQuery& text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(),
        right.begin(), right.end(),
        inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult
NotQuery::eval(const TextQuery& text) const
{
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

/*
** other functions
 */
std::ostream &print(std::ostream &os, const QueryResult &qr)
 {
     os << qr.sought << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 1 ? "times" : "time") << std::endl;
     for (auto num : *qr.lines)
         os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << std::endl;
     return os;
 }

QueryResult
TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

TextQuery::TextQuery(std::ifstream &is): file(new std::vector<std::string>)
{
    std::string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word, str;
        while (line >> word) {
            std::remove_copy(word.begin(), word.end(),
                back_inserter(str), ',');
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}
