#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int need=target-nums[i];
            if(mp.find(need)!=mp.end())
            {
                return{mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: ";
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}