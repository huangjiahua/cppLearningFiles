#include <iostream>
#include <vector>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<string> vi(10, "hi");
    cout << vi.size() << " " << vi.empty() << endl;
    for(auto it = vi.cbegin(); it != vi.cend(); it++)
        cout << *it << " ";
    return 0;
}
