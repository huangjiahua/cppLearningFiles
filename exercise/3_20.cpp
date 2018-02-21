#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    std::vector<int> v;
    int input;
    while(cin >> input)
        v.push_back(input);

    for(decltype(v.size()) i = 0; i <= v.size() - i; i ++)
        cout << v[i] + v[v.size() - i] << " ";


    return 0;
}
