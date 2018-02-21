#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool equal(const vector<int> &v1, const vector<int> &v2)
{
    if (v1 == v2)
        return 1;
    return 0;
}

bool equal(const vector<int> &v1, const list<int> &li)
{
    vector<int> v2(li.begin(), li.end());
    if (v1 == v2)
        return 1;
    return 0;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    list<int> li{1, 2, 3, 4, 5};
    cout << equal(vec, li) << endl;

    return 0;
}
