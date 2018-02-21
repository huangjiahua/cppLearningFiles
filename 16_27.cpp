#include <iostream>
#include <vector>
#include "Blob.h"

using namespace std;
template class Blob<string>;

class NoDefault {
public:
    NoDefault() = delete;
    NoDefault(int i): test(i) { }
private:
    int test;
};



int main()
{
    return 0;
}
