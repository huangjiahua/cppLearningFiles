#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

void doSomething(int num, char c) {
    try {
        default_random_engine dre(42*c);
        uniform_int_distribution<int> id(10, 1000);
        for (int i=0; i<num; ++i) {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
    }
    catch (const exception& e) {
        cout << "THREAD-EXCEPTION (thread "
             << this_thread::get_id() << "): " << e.what() << endl;
    }
    catch(...) {
        cerr << "THREAD-EXCEPTION (thread "
             << this_thread::get_id() << ")" << endl;
    }
}

int main(int argc, char const *argv[]) {
    /*
    try {
        thread t1(doSomething, 5, '.');
        cout << "- started fg thread " << t1.get_id() << endl;

        for (int i=0; i<5; ++i) {
            thread t(doSomething, 10, 'a'+i);
            cout << "- detach started bg thread " << t.get_id() << endl;
            t.detach();
        }
        cin.get();
        cout << "- join fg thread " << t1.get_id() << endl;
        t1.join();
    }
    catch(const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }
    */
    std::thread t1(doSomething, 5, '.');
    std::thread t2(doSomething, 5, '+');
    std::thread t3(doSomething, 5, '*');
    std::cout << "t3 ID:       " << t3.get_id() << std::endl;
    std::cout << "main ID:     " << std::this_thread::get_id() << std::endl;
    std::cout << "nothread ID: " << std::thread::id() << std::endl;

    return 0;
}
