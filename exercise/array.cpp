#include <iostream>

using namespace std;

int main()
{
    char s[] = "good morning";
    char *p1 = &s[3];
    char *p2 = &s[5];
    p1 += p2 - p1;
    cout << *p1 << endl;

    return 0;
}
