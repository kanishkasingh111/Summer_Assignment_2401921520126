#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(empty())
        return 0;
        else if(!st2.empty())
        {
            int element=st2.top();
            st2.pop();
            return element;
        }
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int element=st2.top();
            st2.pop();
            return element;
        }
    }
    
    int peek() {
        if(empty())return 0;
        if(!st2.empty())
        return st2.top();
        else
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}