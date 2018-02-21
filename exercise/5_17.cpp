#include <iostream>
#include <vector>

using namespace std;
bool prefix(vector<int> va, vector<int> vb);

int main()
{
    vector<int> va = {1, 2, 3, 4, 5, 6};
    vector<int> vb = {0, 2, 3};
    cout << prefix(va, vb) << endl;

    return 0;
}

bool prefix(vector<int> va, vector<int> vb)
{
    decltype(va.size()) i = 0;
    for( ;
        i != va.size() && i != vb.size() && va[i] == vb[i];
        ++i)
        ;
    if(i == va.size() || i == vb.size())
        return true;
    else
        return false;
}
