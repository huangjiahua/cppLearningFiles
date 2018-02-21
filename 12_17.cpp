#include <iostream>
#include <memory>

using namespace std;
using IntP = unique_ptr<int>;

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    IntP p0(ix);

    IntP p1(pi);

    IntP p2(pi2);

    IntP p3(&ix);

    IntP p4(new int(2048));

    IntP p5(p2.get());
}
