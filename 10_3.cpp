#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<double> vi{1.1, 2.2, 3.2, 4.4, 5.4};
    cout << accumulate(vi.cbegin(), vi.cend(), 0.0) << endl;
}
