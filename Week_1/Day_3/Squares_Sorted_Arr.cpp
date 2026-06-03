#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        ans.push_back(nums[i]*nums[i]);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter size of the array :";
    cin>>n;
    vector<int>nums(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    cin>>nums[i];

    Solution obj;
    vector<int>ans=obj.sortedSquares(nums);

    cout<<"Sorted squares: ";
    for(int x:ans)
    cout<<x<<" ";

    return 0;
}