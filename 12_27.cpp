#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class QueryResult;

class TextQuery {
public:
    TextQuery();
    TextQuery(ifstream &);
    QueryResult query(string &);
private:
    shared_ptr<vector<string>> file_ptr;
};

class QueryResult {

};

TextQuery::TextQuery(): file_ptr(make_shared<vector<string>>()) { }
TextQuery::TextQuery(ifstream &input): TextQuery()
{
    string to_store;
    while (getline(input, to_store))
        file_ptr->push_back(to_store);
}
