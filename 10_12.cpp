#include <iostream>
#include <string>
#include <vector>
#include "sales_data.h"

using namespace std;

bool compareIsbn(Sales_data d1, Sales_data d2)
{
    return d1.isbn() < d2.isbn();
}

int main()
{
    vector<Sales_data> vs;
    for (int i = 0; i != 3; ++i) {
        Sales_data item(cin);
        vs.push_back(item);
    }
    sort(vs.begin(), vs.end(),
        [](const Sales_data &a, const Sales_data &b)
            {return a.isbn() < b.isbn();});
    for (const auto &v : vs)
        cout << v.isbn() << endl;

    return 0;
}
