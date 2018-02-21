#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
size_t count(const vector<T> &vec, const T value)
{
    size_t n = 0;
    for (auto iter = vec.cbegin();
         iter != vec.cend();
         ++iter)
         if (*iter == value)
            ++n;
    return n;
}

template <>
size_t count<const char*>(const vector<const char*> &vec,
        const char* value)
{
    size_t n = 0;
    for (auto iter = vec.cbegin();
         iter != vec.cend();
         ++iter)
        if (strcmp(*iter, value) == 0)
            ++n;
    return n;
}

int main()
{
    vector<const char*> vi{"asdfj", "a", "a", "b", "c", "a"};
    cout << count(vi, "a") << endl;

}
