#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    vector<string> vs;
    list<char *> lc{"hi", "hello", "how are you"};
    vs.assign(lc.begin() lc.end());
    for (auto i : vs)
        cout << i << endl;;

    return 0;
}
