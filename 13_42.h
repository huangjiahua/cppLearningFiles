#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include "StrVec.h"
using namespace std;

class QueryResult;
class TextQuery {
public:
    using line_no = size_t;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s,
                shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<StrVec> f):
        sought(s), lines(p), file(f) { }
private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<StrVec> file;
};


TextQuery::TextQuery(ifstream &is): file(new StrVec)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word, str;
        while (line >> word) {
            std::remove_copy(word.begin(), word.end(),
                back_inserter(str), ',');
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? "times" : "time") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}
