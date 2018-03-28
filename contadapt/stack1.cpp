#include <iostream>
#include <stack>
#include <list>
using namespace std;

int main(int argc, char const *argv[]) {
    stack<int, list<int>> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << ' ';
    st.pop();
    cout << st.top() << ' ';
    st.pop();

    st.top() = 77;

    st.push(4);
    st.push(5);

    st.pop();

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
    return 0;
}
