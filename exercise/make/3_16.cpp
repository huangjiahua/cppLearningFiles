#include <iostream>
#include <vector>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
    vector<int> vi{10, 42};
    cout << vi.size() << " " << vi.empty() << endl;
    for(auto i : vi)
        cout << i << " ";
    return 0;
}
