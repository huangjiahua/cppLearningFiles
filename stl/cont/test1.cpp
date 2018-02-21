#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_multiset<int> st = {1, 2, 2, 3, 3, 3, 3};
    for (const auto& i : st)
        cout << i << " ";
    cout << endl;
    vector<int> v{st.equal_range(2).first, st.equal_range(2).second};
    for (const auto& i : v)
        cout << i << " ";
    cout << endl;
}
