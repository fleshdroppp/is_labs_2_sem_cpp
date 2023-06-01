#include "iostream"
#include "Stack.h"
#include "cstdlib"
#include "Exception.h"

using namespace std;

template <typename T> double power(T num, int n) {
    double result{1};
    int loopC = abs(n);
    for (int i = 0; i < loopC; i++) {
        if (n > 0) {
            result *= num;
        } else {
            result /= num;
        }
    }
    return result;
}

int main() {

    cout << power(10, 2) << '\n';

    Stack<10, string> st;

    try {
        st.push("abc");
        st.push("cde");
        st.push("afg");
        cout << st.pop() << endl;
        cout << st.pop() << endl;
        cout << st.pop() << endl;
        cout << st.pop() << endl;
    } catch (exception &e) {
        cout << e.what();
    }

}