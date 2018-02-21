#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.cend() - 1;
    for ( ; iter != vi.begin() - 1; --iter)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
