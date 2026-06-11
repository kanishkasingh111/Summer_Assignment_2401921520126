#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

    string solve(string &s,int &i)
    {
        string ans="";
        while(i<s.size() && s[i]!=']'){
            if(isdigit(s[i])){
                int num=0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i++;
                string temp=solve(s,i);
                i++;
                while(num--)
                ans+=temp;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }

    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};

int main()
{
    string s;
    cout<<"Enter encoded string: ";
    cin>>s;

    Solution obj;
    cout<<"Decoded String: "<<obj.decodeString(s)<<endl;

    return 0;
}