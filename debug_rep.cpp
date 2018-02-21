#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template <typename T> string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

string debug_rep(const string &s)
{
    return '"' + s + '"';
}

int main()
{
    string s("hi");
    cout << debug_rep("hi") << endl;
}
