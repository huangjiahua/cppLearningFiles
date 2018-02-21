#include <iostream>
#include <tuple>
#include <string>
#include <vector>

using namespace std;

int main()
{
    tuple<string, vector<string>, pair<string, int>>
        someVal{"good morning", {"hi", "hello"}, {"yeah", 3}};
    cout << get<1>(someVal)[1] << endl;
}
