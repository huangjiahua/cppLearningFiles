#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

int main(int argc, char const *argv[]) {
    ostringstream os;
    os << "dec: " << 15 << hex << " hex: " << 15 << endl;
    cout << os.str() << endl;

    bitset<15> b(5789);
    os << "float: " << 4.67 << " bitset: " << b << endl;

    os.seekp(0);
    os << "oct: " << oct << 15;
    cout << os.str() << endl;
    return 0;
}
