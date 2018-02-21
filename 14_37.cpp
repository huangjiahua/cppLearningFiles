#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Equal {
public:
    Equal(int old): old_value(old) { }
    bool operator()(int value)
    {
        if (value == old_value)
            return true;
        return false;
    }
private:
    int old_value;
};

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6};
    replace(vec.begin(), vec.end(), 4, 5);
    replace_if(vec.begin(), vec.end(), Equal(5), 7);
    for (const auto &i : vec)
        cout << i << " ";

    return 0;

}
