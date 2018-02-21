#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main()
{
    using placeholders::_1;
    vector<int> vi{1, 2, 4, 8, 16, 2048, 4056, 9112};
    vector<string> vs{"good", "better", "good", "best", "good"};

    size_t count = 0;
    count = count_if(vi.begin(), vi.end(),
        bind(greater<int>(), _1, 1024));
    cout << count << endl;

    string pooh = "good";
    auto found = find_if(vs.begin(), vs.end(),
        bind(not_equal_to<string>(), _1, pooh));
    cout << *found << endl;

    transform(vi.begin(), vi.end(), vi.begin(),
        bind(multiplies<int>(), _1, 2));
    for (const auto &i : vi)
        cout << i << " ";
}
