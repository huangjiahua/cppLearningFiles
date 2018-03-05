#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
using namespace std::placeholders;

int main()
{
    map<string, int> coll{{"1", 1}, {"2", 2}, {"3", 3}};

    int sum = accumulate(coll.begin(), coll.end(),
                         0,
                         bind(plus<int>(),
                         _1,
                         bind(&map<string, int>::value_type::second,
                              _2)));
    cout << sum << endl;
}
