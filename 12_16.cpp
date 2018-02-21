#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> up(new int(30));
    auto up2 = up; 

    return 0;
}
