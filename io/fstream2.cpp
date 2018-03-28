#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string s("hello");
    std::ofstream("fstream2.txt") << s << std::endl;

    std::ofstream("fstream2.txt", std::ios::app) << "world" << std::endl;
}
