#include <utility>
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;
class Fracts
{
typedef unsigned long long num;
private:
    static num divisor(num x, num y)
    {
       while(x != y) {
          x < y ? y = y - x : x = x - y;
       }
       return x;
    }

    static num multiple(num x, num y)
    {
       int div = divisor(x, y);
       return x * y / div;
    }

public:
    static std::string
    convertFrac(std::vector<std::vector<unsigned long long>> &lst)
    {
        ostringstream os;
        unsigned long long denominator = 1;
        for (std::vector<unsigned long long>&v : lst) {
            denominator = multiple(denominator, v[1]);
        }
        for (const auto &v : lst) {
            os << "(" << v[0] * denominator / v[1] << "," << denominator << ")";
        }
        return os.str();
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<unsigned long long>> a{{1, 2}, {1, 3}, {1, 4}};
    cout << Fracts().convertFrac(a) << endl;;
    return 0;
}
