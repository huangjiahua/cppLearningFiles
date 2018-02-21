#include <iostream>
#include "Quote.h"

using namespace std;

int main()
{
    Quote qb("A", 34.0);
    print_total(cout, qb, 3);
    Bulk_quote bb("B", 35.0, 5, 0.2);
    print_total(cout, bb, 6);
    Limit_quote lb("C", 34.0, 5, 0.2);
    print_total(cout, lb, 6);
}
