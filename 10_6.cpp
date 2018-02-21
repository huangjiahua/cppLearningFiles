#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v(10, 1);
    fill_n(v.begin(), 10, 0);

    for (auto i : v)
        cout << i << " ";
}
