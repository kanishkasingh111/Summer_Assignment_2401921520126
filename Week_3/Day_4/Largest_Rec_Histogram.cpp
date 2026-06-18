#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> nsl(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> left(n);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }
        return left;
    }

    vector<int> nsr(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> right(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }
        return right;
    }

    int largestRectangleArea(vector<int>& heights)
    {
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution obj;
    int ans = obj.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << ans << endl;

    return 0;
}