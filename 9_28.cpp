#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

void insert_string(forward_list<string> &fstr, const string &target,
    const string &res)
{
    auto curr = fstr.begin();
    auto prev = fstr.before_begin();
    for ( ; curr != fstr.end() && *curr != target; ++curr, ++prev)
        ;
    if (curr == fstr.end())
        fstr.insert_after(prev, res);
    else
        fstr.insert_after(curr, res);
}


int main()
{
    forward_list<string> fstr{"hello", "my", "friend"};
    string word = "good";
    insert_string(fstr, "hey", word);
    for (const auto & str : fstr)
        cout << str << " " << flush;

    return 0;
}
