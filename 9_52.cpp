#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string test;
    stack<int> pr;
    cin >> test;

    for (const auto & ch : test) {
        if (ch == '(')
            pr.push(0);
        else if (ch == ')') {
            if (pr.empty()) {
                cout << "WRONG USAGE" << endl;
                return -1;
            }
            else
                pr.pop();
        }
    }
    if (pr.empty())
        cout << "RIGHT USAGE" << endl;
    else
        cout << "WRONG USAGE" << endl;

    return 0;
}
