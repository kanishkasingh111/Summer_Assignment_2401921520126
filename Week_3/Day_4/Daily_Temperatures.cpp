#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            st.pop();
            if(!st.empty())
            ans[i]=st.top()-i;

            st.push(i);
        }
        return ans;
    }
};

int main()
{
    vector<int>temperatures={73,74,75,71,69,72,76,73};

    Solution obj;
    vector<int>ans=obj.dailyTemperatures(temperatures);
    cout<<"Answe: ";
    for(int x:ans)
    cout<<x<<" ";
    cout<<endl;

    return 0;
}