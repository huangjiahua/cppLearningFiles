#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    ostream hexout(cout.rdbuf());
    hexout.setf(ios::hex, ios::basefield);
    hexout.setf(ios::showbase);

    hexout << "hexout: " << 177 << " ";
    cout   << "cout:   " << 177 << " ";
    hexout << "hexout: " << -49 << " ";

    cout   << "cout:   " << -49 << " ";
    hexout << endl;

    return 0;
}
