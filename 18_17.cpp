#include <iostream>

namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;
using Exercise::limit;

void manip() {
    using Exercise::ivar;
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
    ++::ivar;
    std::cout << ivar << std::endl;
    std::cout << ::ivar << std::endl;
}

int main()
{
    manip();
    return 0;
}
