#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    list<int> coll;

    for (int i = 1; i <= 6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }

    for (const auto& i : coll)
        cout << i << ' ';
    cout << endl;
    coll.erase(remove(coll.begin(), coll.end(), 3));

    for (const auto& i : coll)
        cout << i << ' ';
    cout << endl;
    coll.remove(4);

    for (const auto& i : coll)
        cout << i << ' ';
    cout << endl;



}
