#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Test {
public:
    Test(size_t mi, size_t ma): min(mi), max(ma) { }
    bool operator()(string s)
    {
        return min <= s.size() && s.size() <= max;
    }
private:
    size_t min;
    size_t max;
};


int main()
{
    ifstream input("8_4.cpp");
    size_t count = 0;
    string word;
    Test test(1, 10);

    while (input >> word)
        if (test(word))
            ++count;

    cout << count << endl;

    return 0;
}
