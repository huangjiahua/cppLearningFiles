#include <string>
#include <vector>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
};

std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k)
{
    if (strarr.size() == 0 || k > strarr.size() || k <=0)
        return "";
    int maxsize = 0, index = 0;
    for (int i = 0; i + k - 1 < strarr.size(); ++i) {
        int size = 0;
        for (int j = i; j < i + k; ++j)
            size += strarr[j].size();
        if (size > maxsize) {
            index = i;
            maxsize = size;
        }
    }
    std::string ret;
    for (int i = index; i < index + k; ++i)
        ret += strarr[i];
    return ret;
}
