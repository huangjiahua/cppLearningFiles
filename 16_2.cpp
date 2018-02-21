#include <iostream>
#include "compare.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << compare(1, 2) << endl;
    cout << compare(23.43, 54.234) << endl;
    cout << compare(string("good"), string("bad")) << endl;
    vector<string> v1{"good", "better", "best"};
    vector<string> v2{"bad", "worse", "worst"};
    cout << compare(v1, v2) << endl;


    return 0;
}
