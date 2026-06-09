#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>findAnagrams(string s, string p) {

        vector<int>result;
        if(p.size()>s.size()) return result;

        int freqP[26] = {0};
        int freqS[26] = {0};
        
        for(char c:p)
            freqP[c-'a']++;

        int k=p.size();
        for(int i=0;i<k;i++)
            freqS[s[i]-'a']++;

        if(equal(freqP,freqS))
            result.push_back(0);

        for(int i=k;i<s.size();i++) {

            freqS[s[i]-'a']++;       
            freqS[s[i-k] -'a']--;

            if(equal(freqP,freqS))
                result.push_back(i-k+1);
        }
        return result;
    }

private:
    bool equal(int a[], int b[]) {
        for(int i=0;i<26;i++) {
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};

int main() {
    string s,p;

    cout<<"Enter string s: ";
    cin>>s;

    cout<<"Enter string p: ";
    cin>>p;

    Solution obj;

    vector<int> ans=obj.findAnagrams(s, p);

    cout<<"Indices: ";
    for(int x:ans)
        cout<<x<<" ";
    return 0;
}