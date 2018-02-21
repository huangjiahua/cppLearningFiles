#include <iostream>
#include <fstream>
#include <string>
#include "sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sales_data total;
    ifstream input;
    ofstream output;
    if (argc < 3)
        return 1;
    input.open(argv[1]);
    output.open(argv[2], ofstream::app);
    if (read(input, total)) { //if the total is intialized then revenue is no 0
        Sales_data trans;
        while (read(input, trans)) {
            if (trans.isbn() == total.isbn()) {
                total.combine(trans);
            }
            else {
                print(output, total);
                total = trans;
            }
        }
        cout << "\n";
        print(output, total);
        cout << endl;
    }
    cout << "NO DATA?" << endl;

}
