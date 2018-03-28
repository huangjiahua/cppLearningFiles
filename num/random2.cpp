#include <random>
#include <iostream>
#include <sstream>

void printNumbers(std::default_random_engine& dre) {
    for (int i = 0; i < 6; ++i) {
        std::cout << dre() << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    std::default_random_engine dre;
    printNumbers(dre);

    std::default_random_engine dre2;
    printNumbers(dre2);

    std::default_random_engine dre3(42);
    printNumbers(dre3);

    std::stringstream engineState;
    engineState << dre;

    printNumbers(dre);

    engineState >> dre;
    printNumbers(dre);

    engineState.clear();
    engineState.seekg(0);
    engineState >> dre;
    dre.discard(2);
    printNumbers(dre);
    return 0;
}
