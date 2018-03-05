#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;


class IntPart
{
    typedef long long lint;
public:
    static std::string part(lint n);
public:
    static std::vector<std::vector<lint>>
        partition(lint n);
    static std::vector<std::vector<lint>>
        partition_x(lint n, lint x);
    static lint biggest_next(lint n, lint x);
};

std::string IntPart::part(lint n)
{
    std::ostringstream os;
    std::vector<lint> result;
    for (lint i = 1; i <= n; ++i) {
        std::vector<std::vector<lint>> v = partition_x(n, i);
        for (const std::vector<lint> &vi : v) {
            result.push_back(std::accumulate(vi.begin(), vi.end(),
                                               1,
                                               std::multiplies<lint>()));
        }
    }
    std::stable_sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    lint range = result.back() - result.front();
    lint sum = std::accumulate(result.begin(), result.end(),
                               0,
                               std::plus<lint>());
    double average = static_cast<double>(sum) /
        static_cast<double>(result.size());
    double median = result.size() % 2 ? result[result.size() / 2] :
        static_cast<double>(result[result.size() / 2] +
        result[result.size() / 2 - 1]) /
        static_cast<double>(2);
    os << "Range: " << range << " Average: "
       << std::setiosflags(std::ios::fixed) << std::setprecision(2)
       << average
       << " Median: " << median; // iomanip
    return os.str();
}


std::vector<std::vector<IntPart::lint>>
    IntPart::partition_x(lint n, lint x)
{
    if (x == 1)
        return {{n}};
    std::vector<std::vector<lint>> ret;
    for (lint i = x - 1; i <= n - n/x; ++i) {
        for (std::vector<lint> &v : partition_x(i, x-1)) {
            v.push_back(n - i);
            ret.push_back(std::move(v));
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    std::cout << IntPart::part(8) << std::endl;
}
