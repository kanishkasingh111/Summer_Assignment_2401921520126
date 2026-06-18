#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string token:tokens)
        {
            if(token=="+" || token=="*" || token=="-" || token=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();

                if(token=="+")
                st.push(b+a);
                else if(token=="-")
                st.push(b-a);
                else if(token=="*")
                st.push(b*a);
                else
                st.push(b/a);
            }
            else
            st.push(stoi(token));
        }
        return st.top();
    }
};

int main()
{
    vector<string>tokens={"2","1","+","3","*"};
    Solution obj;
    cout<<"Answer: "<<obj.evalRPN(tokens)<<endl;

    return 0;
}