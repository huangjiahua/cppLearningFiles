#include <iostream>
using std::cout;
using std::endl;

namespace primerLib {
    void compute() { cout << "pc" << endl; }
    void compute(const void *) { cout << "pc*" << endl; }
}

using namespace primerLib;
void compute(int) { cout << "ci" << endl; }
void compute(double, double = 3.4) { cout << "dd" << endl; }
void compute(char*, char* = 0) { cout << "**" << endl; }

int main()
{
    char ch = 'c';
    const char *pc = &ch;
    compute(pc);
}
