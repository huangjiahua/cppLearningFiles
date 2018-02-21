#include <iostream>

using namespace std;

constexpr size_t scale(size_t cnt)
{
    return cnt;
}

constexpr bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    const int cnt = 1;
    cout << scale(cnt) << endl;
    const string str1 = "good";
    const string str2 = "better";
    cout << isShorter(str1, str2) << endl;

}
