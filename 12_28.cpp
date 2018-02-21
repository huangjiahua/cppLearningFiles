#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    cout << "input the file name" << endl;
    string file;
    string line;
    cin >> file;
    ifstream input(file);

    vector<string> lines;
    map<string, set<size_t>> word_map;
    while (getline(input, line))
        lines.push_back(line);

    while (true) {
        string q;
        size_t count = 0;
        size_t line_count = 0;
        set<size_t> in_line;
        if (!(cin >> q))
            break;
        for (const auto &l : lines) {
            istringstream this_l(l);
            string word;
            while (this_l >> word)
                if (word == q) {
                    ++count;
                    in_line.insert(line_count);
                }
            ++line_count;
        }
        word_map.emplace(q, in_line);
        cout << q << " occurs " << count << " times" << endl;
        for (const auto &i : in_line)
            cout << "\t(line " << i << ") " << lines[i] << endl;
    }
    return 0;
}
