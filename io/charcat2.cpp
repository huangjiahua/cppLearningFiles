#include <iostream>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[]) {
    istreambuf_iterator<char> inpos(cin);
    istreambuf_iterator<char> endpos;

    ostreambuf_iterator<char> outpos(cout);

    while (inpos != endpos) {
        *outpos = *inpos;
        ++inpos;
        ++outpos;
    }
    return 0;
}
