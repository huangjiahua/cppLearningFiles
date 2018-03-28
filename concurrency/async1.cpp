#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething(char c) {
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10, 1000);

    for (int i = 0; i < 1000; ++i) {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }

    return c;
}

int funct1() {
    return doSomething('.');
}

int funct2() {
    return doSomething('+');
}

int main(int argc, char const *argv[]) {
    std::cout << "starting func1() in background"
              << " and func2() in foreground:" << std::endl;
    std::future<int> result1(std::async(funct1));

    int result2 = funct2();

    int result = result1.get() + result2;

    std::cout << "\nresult of func1() + func2(): " << result;
    std::cout << std::endl;
    return 0;
}
