#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
       int freq[26]={0};
       for(int i=0;i<s.size();i++)
        freq[s[i]-'a']++;
       for(int i=0;i<s.size();i++)
       {
        if(freq[s[i] - 'a'] == 1)
        return i;
       }
       return -1;
    }
};

int main()
{
    string s;
    cout<<"Enter a  string : ";
    cin>>s;

    Solution obj;
    int ans=obj.firstUniqChar(s);

    cout<<"Index of first unique character: "<<ans<<endl;

    return 0;

}