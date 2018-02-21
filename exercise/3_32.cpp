#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list1(10);
    for (decltype(list1.size()) i = 0; i < 10; i++)
        list1[i] = i;

    vector<int> list2 = list1;

    for (auto it = list1.cbegin(); it != list1.cend(); it++)
        cout << *it << " ";
    return 0;
}
