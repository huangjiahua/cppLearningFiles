#include <iostream>
namespace blip {
    int i = 16, j = 15, k = 23;
}

int j = 0;

int main()
{
    using namespace blip;
    ++i;
    ++blip::j;
    ++::j;
    int k = 97;
    ++k;
    std::cout << k << std::endl;

}
