#include "strblob.h"

using namespace std;

int main()
{
    StrBlob sb;
    string str;
    while (cin >> str)
        sb.push_back(str);

    for (ConstStrBlobPtr ptr(sb.cbegin()), pend(sb.cend());
         ptr.curr_size() != pend.curr_size(); ptr = ptr.incr())
         cout << ptr.deref() << endl;

    return 0;
}
