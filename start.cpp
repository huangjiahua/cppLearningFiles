#include <iostream>
#include <string>
#include "Sales_data.h"

using namespace std;

int main()
{
	Sales_data data1("isbn", 12, 12);
	cout << endl;
	Sales_data data2;
	cout << endl;
	Sales_data data3("isbn");
	cout << endl;
	Sales_data data4(cin);

}
