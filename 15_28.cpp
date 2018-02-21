#include <iostream>
#include <vector>
#include "Quote.h"

using namespace std;

int main()
{
    Basket bsk;
    for (int i = 0; i < 20; ++i)
        bsk.add_item(Quote("001", 50));
    for (int i = 0; i < 20; ++i)
        bsk.add_item(Bulk_quote("002", 50, 20, 0.25));
    bsk.total_receipt(cout);

    return 0;
}
