#include <iostream>
#include "compare.h"

using namespace std;

void print(int i)
{
    cout << "int" << endl;
}


template <typename T>
void print(const T &obj)
{
    cout << obj << endl;
}

int main()
{
    int i = 0;
    int n = 3;
    int *const p = &i;
}
