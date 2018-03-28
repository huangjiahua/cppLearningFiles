#include <iostream>
#include <exception>
#include "Stack.h"
using namespace std;

int main(int argc, char const *argv[]) {
    try {
        Stack<int> st;

        st.push(1);
        st.push(2);
        st.push(3);

        cout << st.pop() << ' ';
        cout << st.pop() << ' ';

        st.top() = 77;

        st.push(4);
        st.push(5);

        st.pop();

        cout << st.pop() << ' ';
        cout << st.pop() << endl;
        cout << st.pop() << endl;

        st.push(3);
        st.push(2);
        cout << st.pop() << endl;
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
