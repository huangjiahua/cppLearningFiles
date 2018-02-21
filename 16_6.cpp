#include <iostream>

template<typename T, unsigned N>
T *myBegin(T (&arr)[N])
{
    return arr;
}

template<typename T, unsigned N>
T *myEnd(T (&arr)[N])
{
    return arr + N;
}

int main()
{
    char str[] = "good";
    for (char *i = myBegin(str); i != myEnd(str); ++i)
        std::cout << *i;

    std::cout << std::endl;
}
