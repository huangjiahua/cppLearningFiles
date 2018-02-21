#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
** QueryResult
 */
class QueryResult {

};
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
    std::string rep() const
    {
        cout << "Query::rep()" << endl;
        return q->rep();
    }
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
    WordQuery(const std::string &s): query_word(s)
    {
        cout << "WordQuery(const string&)" << endl;
    }
    QueryResult eval(const TextQuery &t) const override
        { return t.query(query_word); }
    std::string rep() const override
    {
        cout << "WordQuery::rep()" << endl;
        return query_word;
    }
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
Query::Query(const std::string &s): q(new WordQuery(s))
{
    cout << "Query(const string&)" << endl;
}

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
