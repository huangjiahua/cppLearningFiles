#include "algostuff.h"
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll:     ");

    rotate(coll.begin(),
           coll.begin() + 1,
           coll.end());
    PRINT_ELEMENTS(coll, "one left: ");

    rotate(coll.begin(),
           find(coll.begin(), coll.end(), 4),
           coll.end());
    PRINT_ELEMENTS(coll, "4 first:  ");
    return 0;
}
