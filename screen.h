#include <string>

using namespace std;
typedef size_t pos;

template <pos H, pos N>
class Screen {
    Screen(): cursor(0) { }
    Screen(string str, pos n = 0): contents(str), cursor(n) { }

private:
    string contents;
    pos cursor;
};
