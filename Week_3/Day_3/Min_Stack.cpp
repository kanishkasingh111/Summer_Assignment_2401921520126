#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int>st;
    stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minSt.empty() || value <= minSt.top())
        minSt.push(value);
    }
    
    void pop() {
        if(st.top() == minSt.top())
        minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return minSt.top();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Current Top: " << ms.top() << endl;
    cout << "Current Minimum: " << ms.getMin() << endl;

    ms.pop();
    cout << "\nAfter one pop:\n";

    cout << "Current Top: " << ms.top() << endl;
    cout << "Current Minimum: " << ms.getMin() << endl;

    ms.pop();
    cout << "\nAfter second pop:\n";

    cout << "Current Top: " << ms.top() << endl;
    cout << "Current Minimum: " << ms.getMin() << endl;

    return 0;
}