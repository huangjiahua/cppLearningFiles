#include "Jhlib/JHVec.h"
#include <iostream>

using namespace std;

int main()
{
    JHVec<int> vi({1, 2, 3, 4});
    for (JHVec<int>::value_type* i = vi.begin();
         i != vi.end();
         ++i)
         cout << *i;

    return 0;
}
