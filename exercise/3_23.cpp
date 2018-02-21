#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    for(int i = 0; i < 10; ++i)
        nums.push_back(i);

    for(auto it = nums.begin(); it != nums.end(); it++)
        *it = *it * 2;

    for(auto i : nums)
        cout << i << " ";

    return 0;
}
