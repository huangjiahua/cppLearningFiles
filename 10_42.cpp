#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void elimDups(list<string> &li)
{
    li.sort();
    li.unique();
}

int main()
{
    list<string> ls{"those", "violent", "delights", "have", "violent",
        "ends"};
    elimDups(ls);
    for (const auto &item : ls)
        cout << item << " " << flush;

    return 0;
}
