#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cout << "Wrong" << endl;
        return -1;
    }
    string output = "g++ -std=c++11 ";
    if (argc > 2 && argv[2] == string("-g"))
        output += "-g ";
    string filename(argv[1]);
    auto i = find(filename.begin(), filename.end(), '.');
    if (i == filename.end()) {
        cout << "Wrong" << endl;
        return -1;
    }
    string outfile = string(filename.begin(), i);
    output += filename + " -o " + outfile;
    system(output.c_str());

    return 0;
}
