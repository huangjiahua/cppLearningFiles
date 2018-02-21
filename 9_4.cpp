#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator
int_in_range(vector<int>::iterator beg, vector<int>::iterator e, int i)
{
    while (beg != e) {
        if (*beg == i)
            return beg;
        ++beg;
    }
    return e;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};

    return 0;
}
