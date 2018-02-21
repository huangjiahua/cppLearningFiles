#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string ,vector<int> > msv = { {"good", {1, 2, 3} } };
    map<string, vector<int> >::iterator iter = msv.find("good");
    for (const auto & v : iter->second)
        cout << v << endl;
}
