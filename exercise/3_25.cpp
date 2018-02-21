#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> range(11, 0);
    auto beg = range.begin();
    unsigned input;
    while(cin >> input)
        *(beg + input / 10) += 1;

    for(auto i : range)
        cout << i << " ";

    return 0;
}
