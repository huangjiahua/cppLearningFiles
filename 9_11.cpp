#include <iostream>
#include <vector>

using namespace std;
vector<int> v1 = {1, 2, 3, 4, 5, 6};
vector<int> v2(v1);
vector<int> v3(v2.begin(), v2.end());
vector<int> v4(6, 1);
vector<int> v5;
vector<int> v6(6);
