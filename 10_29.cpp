#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<string> item_iter(cin), eof;
    vector<string> vs;

    while (item_iter != eof)
        vs.push_back(*item_iter++);

    for (const auto & v : vs)
        cout << v << " ";

    cout << endl;
    return 0;
}
