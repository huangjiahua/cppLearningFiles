#include <iostream>
#include <vector>
#include <list>

using namespace std;

void list_to_vector(const list<int> &li, vector<double> &vec)
{
    for(const auto &i : li)
        vec.push_back(i);
}

int main()
{
    vector<double> v;
    list<int> li{1, 2, 3, 4, 5, 6, 7};
    list_to_vector(li, v);
    for (const auto &i : v)
        cout << i << " " << flush;
}
