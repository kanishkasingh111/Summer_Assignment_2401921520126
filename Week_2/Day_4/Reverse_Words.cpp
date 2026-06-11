#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word="";
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            word+=s[i];
            else
            {
                int k=0,j=word.size()-1;
                while(k<j)
                {
                    swap(word[k],word[j]);
                    k++;
                    j--;
                }

                ans+=word;
                ans+=' ';
                word="";
            }
        }
         int k=0,j=word.size()-1;
                while(k<j)
                {
                    swap(word[k],word[j]);
                    k++;
                    j--;
                }

                ans+=word;

        return ans;
    }
};

int main()
{
    string s;
    cout<<"Enter a sentence: ";
    getline(cin,s);

    Solution obj;
    cout<<"Output: "<<obj.reverseWords(s)<<endl;

    return 0;
}