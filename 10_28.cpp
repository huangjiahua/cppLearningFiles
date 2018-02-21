#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

void print(vector<int> &);
void print(list<int> &);

int main()
{
    vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2, v3;
    list<int> v4;
    copy(v1.cbegin(), v1.cend(), back_inserter(v2));
    copy(v1.cbegin(), v1.cend(), inserter(v3, v3.begin()));
    copy(v1.cbegin(), v1.cend(), front_inserter(v4));

    print(v2);
    print(v3);
    print(v4);

    return 0;
}

void print(vector<int> &v)
{
    for (const int &i : v)
        cout << i << " ";
    cout << endl;
}

void print(list<int> &v)
{
    for (const int &i : v)
        cout << i << " ";
    cout << endl;
}
