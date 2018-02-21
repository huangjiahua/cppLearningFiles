#include <vector>
#include <iostream>
#include <algorithm>
#include "print.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(2);
        v.push_back(1);
        v.push_back(0);
    }
    PRINT_ELEMENTS(v);
    auto iter = remove(v.begin(), v.end(), 1);
    PRINT_ELEMENTS(v);
    v.erase(iter, v.end());
    PRINT_ELEMENTS(v);
    return 0;
}
