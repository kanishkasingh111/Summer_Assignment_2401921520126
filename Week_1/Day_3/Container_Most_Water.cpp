#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int area=0,max_area=0;
        while(i<j)
        {
            area=min(height[i],height[j])*(j-i);
            max_area=max(area,max_area);
            if(height[i] < height[j])
            i++;
            else
            j--;
        }
        return max_area;
    }
};

int main()
{
    int n;
    cout<<"Enter size of the heights :";
    cin>>n;
    vector<int>height(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    cin>>height[i];

    Solution obj;
    int ans=obj.maxArea(height);

    cout<<"Maximum Water Container Area :"<<ans<<endl;

    return 0;
}