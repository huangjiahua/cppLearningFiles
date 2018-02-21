#include <iostream>
#include <fstream>
#include "Query.h"

using namespace std;

int main()
{
    ifstream input("alice");
    auto text = TextQuery(input);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    QueryResult rs = q.eval(text);
    print(cout, rs);
}
