#include <forward_list>
#include "../print.hpp"
#include "findbefore.h"
using namespace std;

int main()
{
    forward_list<int> l1 = {1, 2, 3, 4, 5};
    forward_list<int> l2 = {97, 98, 99};


    l1.splice_after(find_before(l2.before_begin(), l2.end(), 99), l2,
                    find_before(l1.before_begin(), l1.end(), 3));

    PRINT_ELEMENTS(l1, "l1: ");
    PRINT_ELEMENTS(l2, "l2: ");
}
