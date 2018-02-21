#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line)) {
        record.str(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }

    for (const auto &item : people) {
        cout << item.name;
        for (const auto &num : item.phones)
            cout << " " << num;

        cout << endl;
    }

    return 0;
}
