#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0};
        for(int i=0;i<magazine.size();i++)
            freq[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.size();i++)
        {
            if(freq[ransomNote[i]-'a']==0)
            return false;
            else
            freq[ransomNote[i]-'a']--;
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
    if(obj.canConstruct(s,t))
    cout<<"Can construct"<<endl;
    else
    cout<<"Cannot construct"<<endl;

    return 0;
}