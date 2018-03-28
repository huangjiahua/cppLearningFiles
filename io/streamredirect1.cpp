#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

void redirect(ostream&);

int main(int argc, char const *argv[]) {
    cout << "the first row" << endl;
    redirect(cout);
    cout << "the last row" << endl;
    return 0;
}

void redirect(ostream& strm) {
    auto del = [&](streambuf* p) {
        strm.rdbuf(p);
    };
    unique_ptr<streambuf, decltype(del)> origBuffer(strm.rdbuf(), del);

    ofstream file("redirect.txt");
    strm.rdbuf(file.rdbuf());

    file << "one row for the file" << endl;
    strm << "one row for the stream" << endl;
}
