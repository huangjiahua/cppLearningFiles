#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char data[100];
    ifstream in("file.txt");
    for (int i = 0; i < 3; ++i) {
        in.getline(data, 20, '\n');
        cout << data << endl;
    }

}
