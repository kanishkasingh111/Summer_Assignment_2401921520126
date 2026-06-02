#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            return true;
            mp[nums[i]]++;
        }
        return false;
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
    Solution obj;
    if(obj.containsDuplicate(nums))
        cout << "True (Duplicate Present)" << endl;
    else
        cout << "False (No Duplicate)" << endl;

    return 0;
}