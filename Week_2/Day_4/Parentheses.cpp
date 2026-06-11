#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void parenth(int n,int left,int right,vector<string>&ans,string &temp)
    {
        if(left+right==2*n)
        {
            ans.push_back(temp);
            return;
        }
        // Left parenth
        if(left<n)
        {
            temp.push_back('(');
            parenth(n,left+1,right,ans,temp);
            temp.pop_back();
        }
        // Right parenth
         if(right<left)
        {
            temp.push_back(')');
            parenth(n,left,right+1,ans,temp);
            temp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        parenth(n,0,0,ans,temp);
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    Solution obj;
    vector<string>ans=obj.generateParenthesis(n);

    cout<<"Valid Parentheses: ";
    for(string s:ans)
    cout<<s<<endl;

    return 0;
}