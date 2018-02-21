#include <iostream>
#include <set>
#include "sales_data.h"
#include <string>

using namespace std;

int main()
{
    multiset<Sales_data> multiData;
    Sales_data data1("001", 13, 24.5);
    multiData.emplace("001", 13, 24.5);

}
