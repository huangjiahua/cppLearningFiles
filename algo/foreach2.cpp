#include "algostuff.h"
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> coll;
    INSERT_ELEMENTS(coll, 1, 9);
    for_each(coll.begin(), coll.end(),
             [](int& elem) {
                 elem += 10;
             });
    PRINT_ELEMENTS(coll);

    for_each(coll.begin(), coll.end(),
             [=](int& elem) {
                 elem += *coll.begin();
             });
    PRINT_ELEMENTS(coll);
    return 0;
}
