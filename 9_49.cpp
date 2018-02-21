#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ascenders("bdfhklt");
string descenders("gjpqy");

int main()
{
    string file;
    ifstream input;
    cin >> file;
    input.open(file);
    if (!input)
        return 1;

    string word, max;
    while (input >> word) {
        if (word.find_first_of(ascenders) == string::npos
            && word.find_first_of(descenders) == string::npos) {
            if (word.size() > max.size())
                max = word;
        }
    }
    cout << max << endl;

    return 0;
}
