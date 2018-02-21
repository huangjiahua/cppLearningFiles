#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

int main(int argc, char const *argv[]) {
    forward_list<int> fl;
    for (int i = 0; i < 10; ++i)
        fl.push_front(i);
    for (const auto& i : fl)
        cout << i << endl;
    return 0;
}
