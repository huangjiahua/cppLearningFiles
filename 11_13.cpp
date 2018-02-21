#include <iostream>
#include <utility>

using namespace std;

int main()
{
    pair<int, int> pt1(1, 2);
    auto pt2 = make_pair(1, 2);
    auto pt3 = pair<int, int>(1, 2);
}
