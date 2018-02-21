#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

map<string, string> build_map(ifstream &);
const string &transform(const string &, const map<string, string> &);
void word_transform(ifstream &map_file, ifstream &input);
unordered_map<string, string> buildMap(ifstream &);
const string &
transform(const string &, const unordered_map<string, string> &);

int main()
{
    ifstream map_file("map_file");
    ifstream input("message");
    word_transform(map_file, input);
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool first_word = true;
        while (stream >> word) {
            if (first_word)
                first_word = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

map<string, string> build_map(ifstream &map_file)
{
    string line;
    map<string, string> rtr;
    while (getline(map_file, line)) {
        auto gap = find(line.cbegin(), line.cend(), ' ');
        string map_key(line.cbegin(), gap);
        ++gap;
        string map_value(gap, line.cend());
        rtr[map_key] = map_value;
    }

    return rtr;
}

const string &
transform(const string &s, const map<string, string> &m)
{
    auto iter = m.find(s);
    if (iter != m.end())
        return iter->second;
    else
        return s;
}

const string &
transform(const string &s, const unordered_map<string, string> &um)
{
    auto iter = um.find(s);
    if (iter != um.end())
        return iter->second;
    else
        return s;
}

unordered_map<string, string> buildMap(ifstream &map_file)
{
    unordered_map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}
