#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
       int start=0;
       int max_len=1;
       for(int i=0;i<s.size();i++)
       {
            int left=i;
            int right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                int len=right-left+1;
                if(len>max_len)
                {
                    start=left;
                    max_len=len;
                }
                left--;
                right++;
            }

            left=i;
            right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                int len=right-left+1;
                if(len>max_len)
                {
                    start=left;
                    max_len=len;
                }
                left--;
                right++;
            }

       }
       return s.substr(start,max_len);
    }
};

int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;

    Solution obj;
    cout<<"Longest Palindromic Substring : "<<obj.longestPalindrome(s)<<endl;

    return 0;
}