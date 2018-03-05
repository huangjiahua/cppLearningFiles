#include "algostuff.h"
using namespace std;

int main()
{
    vector<int> v{7, 5, 6, 2, 3};
    deque<int> d{3, 2, 5, 7, 6};
    cout << is_permutation(v.begin(), v.end(), d.begin()) << endl;
}
