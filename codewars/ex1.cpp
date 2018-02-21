#include <iostream>
#include <cctype>

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s)
{
    std::string ret;
    for (int i = 0; i != s.size(); ++i) {
        char ch = s[i];
        ret += toupper(ch);
        if (i > 0)
            ret += std::string(i, tolower(ch));
        if (i != s.size() - 1)
            ret += '-';
    }
    return ret;
}

int main()
{
    std::cout << Accumul::accum("abcd") << std::endl;
}
