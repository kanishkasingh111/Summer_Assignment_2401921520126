#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>> mp;
        for(string str: strs)
        {
            string temp=str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);

        }
        for(auto it : mp)
            ans.push_back(it.second);
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter no of strings: ";
    cin>>n;

    vector<string>strs(n);
    cout<<"Enter string :";
    for(int i=0;i<n;i++)
    cin>>strs[i];

    Solution obj;
    vector<vector<string>>ans=obj.groupAnagrams(strs);

    cout<<"Group Anagrams: ";
    for(auto grp:ans)
    {
        cout<<"[";
        for(string s:grp)
        cout<<s<<" ";
        cout<<"]\n";
    }
    return 0;
}