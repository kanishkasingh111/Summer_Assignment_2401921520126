#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>&nums) {
        int i=0;
        for(int j=1;j<nums.size();j++) {
            if(nums[j]!=nums[i]) {
                i++;
                nums[i]=nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums(n);
    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    int k = obj.removeDuplicates(nums);
    cout<<"\nNumber of unique elements: "<<k<<endl;
    cout<<"Array after removing duplicates: ";
    for(int i=0;i<k;i++) {
        cout<<nums[i]<<" ";
    }
    return 0;
}