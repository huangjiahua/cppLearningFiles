#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void writeCharsetToFile(const string& filename);
void outputFile(const string& filename);

int main(int argc, char const *argv[]) {
    writeCharsetToFile("charset.out");
    outputFile("charset.out");

    return 0;
}

void writeCharsetToFile(const string& filename) {
    ofstream file(filename);

    if (! file) {
        cerr << "can't open output file \"" << filename << "\""
             << endl;
             exit(EXIT_FAILURE);
    }

    for (int i = 32; i < 256; ++i)
        file << "value: " << setw(3) << i << "   "
             << "char:  " << static_cast<char>(i) << endl;
}

void outputFile(const string& filename) {
    ifstream file(filename);

    if (! file) {
        cerr << "can't open input file \"" << filename << "\""
             << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    while (file.get(c)) {
        cout.put(c);
    }
}
