#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <set>
#include "sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
        bookstore(compareIsbn);

    multiset<Sales_data, decltype(compareIsbn)>::const_iterator
        iter = bookstore.cbegin();

}
