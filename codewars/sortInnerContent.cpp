#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


char* sortTheInnerContent(const char* words, int length)
{
    char *ret = (char *)malloc(length * sizeof(char));
    strcpy(ret, words);
    char *b = ret, *e = ret;
    while (true) {
        while (*e != ' ' && *e != '\0')
            ++e;
        if (*e == '\0')
            break;
        if (e - b > 2) {
            std::sort(b + 1, e - 1, greater<char>());
        }
        b = e;
        while (*b == ' ')
            ++b;
        if (*b == '\0')
            break;
        e = b;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    char word[] = "wait for me";
    cout << sortTheInnerContent(word, strlen(word));

    return 0;
}
