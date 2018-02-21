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

    unique_copy(vi.begin(), vi.end(), out_iter);

    return 0;
}
