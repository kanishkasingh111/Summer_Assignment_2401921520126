#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string temp="";
        int count=1;
        
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==chars[i-1])
            count++;
            else
            {
                temp+=chars[i-1];
                if(count>1)
                temp+=to_string(count);
                count=1;
            }
        }
        temp+=chars.back();
        if(count>1)
        temp+=to_string(count);

        chars.clear();
        for(char ch : temp)
            chars.push_back(ch);

        return temp.size();
    }
};

int main()
{
    int  n;
    cout<<"Enter no of characters: ";
    cin>>n;

    vector<char>chars(n);
    cout<<"Enter characters:\n";
    for(int i=0;i<n;i++)
    cin>>chars[i];

    Solution obj;
    cout<<"Compressed length: "<<obj.compress(chars)<<endl;

    for(char c:chars)
    cout<<c<<' ';

    return 0;
}