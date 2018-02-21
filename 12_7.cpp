#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vec()
{
    auto ptr = make_shared<vector<int>>();
    return ptr;
}

void read_input(shared_ptr<vector<int>> pv)
{
    int i;
    while (cin >> i)
        pv->push_back(i);
}

void print_nums(shared_ptr<vector<int>> pv)
{
    for (const auto &i : *pv)
        cout << i << " ";
    cout << endl;
}

int main()
{
    auto pvi = new_vec();
    read_input(pvi);
    print_nums(pvi);

    return 0;
}
