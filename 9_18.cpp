#include <iostream>
#include <deque>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<string> li;
    string word;
    while(cin >> word)
        li.push_back(word);
    for (list<string>::const_iterator iter = li.cbegin();
        iter != li.cend();
        ++iter)
        cout << *iter << " " << flush;

    return 0;
}
