#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
       sort(s.begin(),s.end()); 
       sort(t.begin(),t.end());
       if(s.size()!=t.size())
       return false; 
       for(int i=0;i<s.size();i++)
       {
            if(s[i]!=t[i])
            return false;
       }
       return true;
    }         
}; 

int main()
{
    string s,t;
    cout<<"Enter first string : ";
    cin>>s;
    cout<<"Enter second string : ";
    cin>>t;

    Solution obj;
    if(obj.isAnagram(s,t))
    cout<<"Anagram"<<endl;
    else
    cout<<"Not Anagram"<<endl;

    return 0;
}
