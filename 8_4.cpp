#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
void store_in_vector(vector<string> &, string);

int main()
{
    string fileName;
    vector<string> vs;
    vector<string> words;
    cin >> fileName;
    store_in_vector(vs, fileName);
    for (const auto &line : vs) {
        istringstream sl(line);
        string word;
        while (sl >> word)
            words.push_back(word);
    }

    for (const auto &item : words)
        cout << item << endl;;

    return 0;
}

void store_in_vector(vector<string> &vs, string fileName)
{
    ifstream op;
    op.open(fileName);
    string buf;
    while (getline(op, buf)) {
        vs.push_back(buf);
    }

}
