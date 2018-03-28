#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    ifstream file;
    for (int i = 1; i < argc; ++i) {
        file.open(argv[i]);

        char c;
        while (file.get(c)) {
            cout.put(c);
        }

        file.clear();

        file.close();
    }
    return 0;
}
