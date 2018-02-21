#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <array>
#include <iterator>
using namespace std;



int main()
{
    array<char, 10> x{'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};
    printf("%s\n", x.data());
}
