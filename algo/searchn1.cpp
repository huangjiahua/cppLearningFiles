#include "algostuff.h"
using namespace std;

int main(int argc, char const *argv[]) {
    deque<int> coll;
    coll = {1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
    PRINT_ELEMENTS(coll);

    deque<int>::iterator pos;
    pos = search_n(coll.begin(), coll.end(),
                   3,
                   7);

    if (pos != coll.end()) {
        cout << "three consecutive elements with value 7 "
             << "start with " << distance(coll.begin(), pos) + 1
             << ". element" << endl;
    }
    else {
        cout << "no four consecutive elements with value 7 found";
    }

    pos = search_n(coll.begin(), coll.end(),
                   4,
                   0,
                   [](int elem, int value) {
                       return elem % 2 == 1;
                   });

    //...
    return 0;
}
