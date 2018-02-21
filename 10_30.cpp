#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> int_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vi;

    while(int_iter != eof)
        vi.push_back(*int_iter++);

    sort(vi.begin(), vi.end());

    for (const auto &v : vi)
        *out_iter++ = v;

    return 0;
}
