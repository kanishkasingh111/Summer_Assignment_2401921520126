#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
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
    obj.moveZeroes(nums);

    cout<<"Array after moving zeroes: ";
    for(int x:nums)
    cout<<x<<" ";

    return 0;
}