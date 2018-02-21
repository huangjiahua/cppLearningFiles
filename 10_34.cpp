#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto riter = vi.crbegin();
    for ( ; riter != vi.crend(); ++riter)
        cout << *riter << " ";
    cout << endl;

    return 0;
}
