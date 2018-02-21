#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
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

template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args& ... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(cerr, "fun", 34, 4.64, string("fuck"), '\n');
}
