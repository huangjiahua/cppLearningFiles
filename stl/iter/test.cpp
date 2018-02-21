#include "distance.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    list<string> ls{"1", "2", "3"};
    cout << ITER::distance(vi.begin(), vi.end()) << endl;
    cout << ITER::distance(ls.begin(), ls.end()) << endl;
}
