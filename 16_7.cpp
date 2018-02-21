#include <iostream>

template<typename T, unsigned N>
constexpr std::size_t sz(const T(&arr)[N])
{
    return N;
}


int main()
{
    char str[] = "fhjaksldfkajsgdkajlsf";
    std::cout << sz(str) << std::endl;
}
