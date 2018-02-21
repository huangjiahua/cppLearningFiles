#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>
#include "print.hpp"

int square(int value)
{
    return value*value;
}

int main()
{
    std::set<int> coll;
    std::vector<int> coll2;

    for (int i = 1; i <= 9; ++i)
        coll.insert(i);
    PRINT_ELEMENTS(coll, "initialized: ");

    std::transform(coll.cbegin(), coll.cend(),
                   std::back_inserter(coll2),
                   square);

    PRINT_ELEMENTS(coll2, "squared:     ");

}
