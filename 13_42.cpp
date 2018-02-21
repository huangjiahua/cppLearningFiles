#include "13_42.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }

}


int main()
{
    string in;
    cin >> in;
    ifstream input(in.c_str());
    runQueries(input);

    return 0;
}
