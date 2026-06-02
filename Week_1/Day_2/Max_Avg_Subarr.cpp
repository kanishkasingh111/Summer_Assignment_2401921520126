#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum=0;
        int curr_sum=0;
        for(int i=0;i<k;i++)
        {
            curr_sum+=nums[i];
        }
        max_sum=curr_sum;
        for(int i=k;i<nums.size();i++)
        {
            curr_sum=curr_sum+nums[i]-nums[i-k];
            if(curr_sum>max_sum)
            {
               max_sum=curr_sum; 
            }
        }
        return (double)max_sum/k;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;

    Solution obj;
    double ans=obj.findMaxAverage(nums, k);
    cout<<"Maximum Average = "<<ans<<endl;

    return 0;
}