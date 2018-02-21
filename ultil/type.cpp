#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

template <typename T>
void foo_impl(const T& val, std::true_type)
{
    cout << "foo() called for pointer to " << *val
         << endl;
}

template <typename T>
void foo_impl(const T& val, std::false_type)
{
    cout << "foo() called for value to " << val
         << endl;
}

template <typename T>
void foo(const T& val)
{
    foo_impl(val, std::is_pointer<T>::value);
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type min(const T1& x, const T2& y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int x = 10;
    double y = 9.9;
    int z = min(x, y);
    cout << z << endl;
}
