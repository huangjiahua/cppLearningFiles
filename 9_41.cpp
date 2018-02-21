#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<char> vc{'a', 'b', 'c', 'd'};
    string str(vc.begin(), vc.end());

    cout << str << endl;


}
