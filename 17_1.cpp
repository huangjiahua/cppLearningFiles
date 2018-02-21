#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    tuple<int, int, int> td{10, 20, 30};
    cout << get<0>(td) << endl;
}
