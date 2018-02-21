#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi_1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi_2(5);

    copy(vi_1.crbegin() + 3, vi_1.crbegin() + 8, vi_2.begin());

    for (auto i : vi_2)
        cout << i << " ";
    
}
