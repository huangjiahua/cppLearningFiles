#include <iostream>
#include <string>

using namespace std;

int main()
{
    string current, previous;
    bool get = false;
    cin >> current;
    previous = current;
    while (cin >> current) {
        if (current == previous) {
            get = true;
            break;
        }
        previous = current;
    }
    if (get) {
        cout << "The word " << current << " is repeated." << endl;
    }
    else
        cout << "No word is repeated" << endl;

    return 0;nomalie
}
