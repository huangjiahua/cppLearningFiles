#include <iostream>
#include <vector>

using namespace std;

template <typename Container>
void print(Container c)
{
    for (typename Container::iterator iter = c.begin();
         iter != c.end();
         ++iter){
        cout << *iter << " ";
    }
}

int main()
{
    vector<int> vi{1, 2 ,3, 4};
    print(vi);

    return 0;
}
