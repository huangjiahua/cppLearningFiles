#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void print_list()
{
    cout << "1. Add family\n"
         << "2. Add children\n"
         << "3. Look up" << endl;
}

int main()
{
    map<string, vector<pair<string,string> > > family_list;
    int choice;
    print_list();
    while (cin >> choice) {
        if (choice == 1) {
            string family_name;
            cin >> family_name;
            family_list[family_name] = {};
        }
        else if(choice == 2) {
            string family_name;
            string children_name;
            string birthday;
            cin >> family_name >> children_name >> birthday;
            if (family_list.find(family_name) != family_list.end())
                family_list[family_name].emplace_back(children_name, birthday);
        }
        else if(choice == 3) {
            string family_name;
            cin >> family_name;
            if (family_list.find(family_name) != family_list.end())
                for (const auto &p : family_list[family_name])
                    cout << p.first << p.second << endl;
        }
        else
            break;
        cout << endl;
        print_list();
    }
}
