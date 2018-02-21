#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int num1 = 0, num2 = 0;
    cout << "Enter two integers: " << endl;
    cin >> num1 >> num2;
    if (num2 < num1) {
        int temp;
        temp = num2;
        num2 = num1;
        num1 = num2;
    }
    while (num1 <= num2) {
        cout << num1 << endl;
        num1++;
    }

    return 0;
}
