#include <iostream>
#include <vector>
#include "MyString.h"

using namespace std;

int main()
{
    vector<String> vs;
    char s[] = "good";
    String s1(s);

    vs.push_back(s1);
}
