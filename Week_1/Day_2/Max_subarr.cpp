#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int> nums(n);

    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    Solution obj;
    int ans=obj.maxSubArray(nums);
    cout<<"Maximum Subarray Sum = "<<ans<<endl;

    return 0;
}