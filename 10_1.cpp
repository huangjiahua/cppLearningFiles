#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    {
        vector<int> vi{1, 2, 3, 4, 1, 2, 3, 4};
        cout << count(vi.cbegin(), vi.cend(), 3);
        cout << endl;
    }
    {
        list<string> li{"good", "better", "best"};
        cout << count(li.cbegin(), li.cend(), "best") << endl;
    }
}
