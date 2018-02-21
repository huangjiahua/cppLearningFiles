#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vi;
    std::string input;
    while(std::cin >> input)
        vi.push_back(input);

    for(auto i : vi)
        std::cout << i << " ";

    return 0;
}
