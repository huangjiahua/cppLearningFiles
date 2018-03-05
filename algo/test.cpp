#include <vector>
#include <iostream>
#include <algorithm>
#include "../stl/print.hpp"

using namespace std;

int main()
{
    vector<int> v;
    v.reserve(100);
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());

    sort(v.begin(), v.end());

    bool i = binary_search(v.begin(), v.end(), 23);
    cout << i << endl;


    PRINT_ELEMENTS(v);
}
