#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
    list<int> li;
    deque<int> d1, d2;
    int num;
    while (cin >> num)
        li.insert(li.end(), num);
    for (auto iter = li.cbegin();
        iter != li.cend();
        ++iter)
        (*iter % 2) ? d2.push_back(*iter) : d1.push_back(*iter);

    return 0;

}
