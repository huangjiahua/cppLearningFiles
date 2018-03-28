#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[]) {
    ostreambuf_iterator<char> bufWriter(cout);
    string s("hello, world\n");
    copy(s.cbegin(), s.cend(),
         bufWriter);
    return 0;
}
