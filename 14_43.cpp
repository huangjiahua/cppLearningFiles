#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    using placeholders::_1;
    int value = 0;
    cin >> value;
    vector<int> vi{2, 3, 5, 7, 11};

    modulus<int> mod;
    auto predicator = [&](int i) { return 0 == mod(value, i); };
    auto is_divisible = any_of(vi.begin(), vi.end(), predicator);
    cout << (is_divisible ? "Yes!" : "No!") << endl;

    return 0;
}
