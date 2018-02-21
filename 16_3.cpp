#include <vector>
#include <string>
#include <list>
#include <iostream>

using namespace std;

template<typename IT, typename T>
IT my_find(IT lhs, IT rhs, const T& value)
{
    for ( ; lhs != rhs; ++lhs)
        if (*lhs == value)
            return lhs;
    return rhs;
}

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6};
    list<string> ls{"good", "better", "best"};
    vector<int>::iterator iter1 = my_find(vi.begin(), vi.end(), 3);
    cout << *iter1 << endl;
    list<string>::iterator iter2 = my_find(ls.begin(), ls.end(), "better");
    cout << *iter2 << endl;
}
