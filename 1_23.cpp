#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item curr, item;

    if (std::cin >> curr) {
        while (std::cin >> item) {
            if (item.isbn() == curr.isbn())
                curr += item;
            else {
                std::cout << curr << std::endl;
                curr = item;
            }
        }
        std::cout << curr << std::endl;
    }

    return 0;
}
