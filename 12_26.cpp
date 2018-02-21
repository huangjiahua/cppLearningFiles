#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q - p != n)
        alloc.construct(q++, s);
    while (q != p)
        alloc.destroy(--q);
    for (q = p; q != p + n; ++q)
        cout << *q << endl;

    alloc.deallocate(p, n);
    return 0;
}
