#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    vector<string>::iterator afterUnique = unique(words.begin(), words.end());
    words.erase(afterUnique, words.end());
}

bool check_size(string str, string::size_type sz)
{
    return str.size() >= sz;
}

string make_plural(int count, const string &str, const string &suffix)
{
    return count > 1 ? str + suffix : str;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
            {return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(),
        [sz](const string &a)
            {return a.size() >= sz;});
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " ";});
    cout << endl;
}

void my_biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
            {return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(),
        bind(check_size, _1, 5));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " ";});
    cout << endl;
}

int main()
{
    vector<string> vs({"these", "violent", "delights", "have", "violent",
        "ends"});
    biggies(vs, 5);
    my_biggies(vs, 5);
}
