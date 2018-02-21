#include <iostream>
#include <vector>

using namespace std;

vector<int> *new_vec()
{
    return (new vector<int>());
}

void read_input(vector<int> *pv)
{
    int i;
    while (cin >> i)
        pv->push_back(i);
}

void print_nums(vector<int> *pv)
{
    for (const auto &i : *pv)
        cout << i << " ";
    delete pv;
    cout << endl;
}

int main()
{
    vector<int> *pvi = new_vec();
    read_input(pvi);
    print_nums(pvi);
    pvi = nullptr;

    return 0;
}
