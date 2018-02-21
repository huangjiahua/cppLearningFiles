#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vi(ia, end(ia));
    list<int> li(vi.begin(), vi.end());


    auto il = li.begin();
    while (il != li.end()) {
        if (*il % 2)
            il = li.erase(il);
        else
            ++il;
    }

    auto iv = vi.begin();
    while (iv != vi.end()) {
        if (!(*iv % 2))
            iv = vi.erase(iv);
        else
            ++iv;
    }

    for (const auto &i : li)
        cout << i << " " << flush;
    cout << endl;
    for (const auto &i : vi)
        cout << i << " " << flush;
    cout << endl;



    return 0;
}
