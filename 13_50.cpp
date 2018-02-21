#include <iostream>
#include <vector>
#include <utility>
#include "MyString.h"

using namespace std;

int main()
{
    vector<String> vs;
    char s1[] = "good";
    char s2[] = "afternoon";
    String v1(s1);
    String v2(s2);
    vs.push_back(v1);
    vs.push_back(std::move(v2));

}
