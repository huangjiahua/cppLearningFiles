#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string input;
    stringstream in;
    getline(std::cin, input);
    in.str(input);
    string output;
    in >> output;
    std::cout << output;

    return 0;

}
