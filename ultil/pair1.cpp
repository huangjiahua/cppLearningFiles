#include <utility>
#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const pair<T1, T2>& p)
{
    return strm << "[" << p.first << "," << p.second << "]";
}

int main()
{
    pair<int, string> a = make_pair(2, "good");
    cout << a << endl;
}
