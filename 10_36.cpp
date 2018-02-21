#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    auto iter = find(vi.crbegin(), vi.crend(), 0);
    ++iter;
    cout << *iter;

    return 0;
}
