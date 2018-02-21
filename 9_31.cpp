#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

int main()
{
    list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin();

    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter);
            advance(iter, 2);
        }
        else
            iter = li.erase(iter);
    }

    for (const auto &i : li)
        cout << i << " " << flush;
}
