#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {
    multiset<int> a = {1, 2, 3, 3, 4, 4, 4};
    auto iter = a.find(4);
    a.erase(iter);
    for (const auto& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
