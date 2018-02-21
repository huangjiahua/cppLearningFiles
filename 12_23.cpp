#include <iostream>

using namespace std;

void concate(char str1[], char str2[])
{
    size_t sz = (sizeof(str1) + sizeof(str2)) / sizeof(char);
    char *ptr = new char[sz];
    char *p = ptr;
    for ( ; *str1 != '\0'; ++str1) {
        *ptr++ = *str1;
    }
    for ( ; *str2 != '\0'; ++str2) {
        *ptr++ = *str2;
    }
    cout << p << endl;
    delete [] p;
}

int main()
{
    concate("good", "mornign");

}
