#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi = {2, 3, 4, 5, 6, 43, 4};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }

    for (const auto &i : vi)
        cout << i << endl;
}
