#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else
            {
                if(st.empty())
                return false;
                
                char top = st.top();
                
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '['))
                    st.pop();
                else
                return false;
            }
        }
        return st.empty();
    }
};


int main() {

    Solution obj;
    string s;

    cout << "Enter parentheses string: ";
    cin >> s;
    if(obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}