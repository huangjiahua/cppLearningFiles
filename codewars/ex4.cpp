#include <string>
#include <cmath>
#include <iostream>

class RevRot
{
public:
    static std::string revRot(const std::string &strng, unsigned int sz);
};

std::string RevRot::revRot(const std::string &str, unsigned int sz)
{
    if (sz <= 0 || str.empty() || sz > str.size())
        return "";
    std::string ret;
    int i = sz;
    for (; i < str.size(); i += sz) {
        std::string curr = str.substr(i - sz, sz);
        int sum = 0;
        for (char ch : curr)
            sum += pow(ch - '0', 3);
        if (sum % 2 == 0)
            ret += std::string(curr.rbegin(), curr.rend());
        else {
            ret += curr.substr(1, sz - 1) + curr[0];
        }
    }
    return ret;
}

int main()
{
    RevRot r;
    std::string s("4123412341324");
    std::cout << r.revRot(s, 4) << std::endl;

    return 0;
}
