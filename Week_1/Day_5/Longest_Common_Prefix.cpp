#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        sort(strs.begin(),strs.end());

        string first=strs[0];
        string last=strs[strs.size()-1];

        string ans="";
        int i=0;
        while(i<first.size() && i<last.size())
        {
            if(first[i]!=last[i])
            break;
            else{
                ans+=first[i];
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter no of strings:";
    cin>>n;
    vector<string>strs(n);

    cout<<"Enter strings:";
    for(int i=0;i<n;i++)
    cin>>strs[i];

    Solution obj;
    string result=obj.longestCommonPrefix(strs);
    cout<<"Longest Common Prefix: "<<result<<endl;

    return 0;
}