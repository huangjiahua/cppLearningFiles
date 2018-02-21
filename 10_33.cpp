#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string file;
    cin >> file;
    ifstream input(file.c_str());
    ofstream out1("out1"), out2("out2");
    istream_iterator<int> in_iter(input), eof;
    ostream_iterator<int> odd_iter(out1, "\n"), even_iter(out2, "\n");

    for_each(in_iter, eof, [&odd_iter, &even_iter](const int &in)
        {*(in % 2 ? odd_iter : even_iter)++ = in;
        });

    return 0;
}
