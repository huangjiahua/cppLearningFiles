#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using std::string;
using std::vector;

int main()
{
    std::function<bool (const std::string)> fcn = &string::length; 
}
