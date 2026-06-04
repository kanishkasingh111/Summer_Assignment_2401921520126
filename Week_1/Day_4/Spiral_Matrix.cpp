#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size(),col=matrix[0].size();
        int top=0,bottom=row-1,left=0,right=col-1;

        while(left<=right && top<=bottom)
        {
            // Print top
            for(int j=left;j<=right;j++)
            ans.push_back(matrix[top][j]);
            top++;
            // Print right
            for(int i=top;i<=bottom;i++)
            ans.push_back(matrix[i][right]);
            right--;
            // Print bottom
            if(top<=bottom){
            for(int j=right;j>=left;j--)
            ans.push_back(matrix[bottom][j]);
            bottom--;
            }
            // Print left
            if(left<=right){
            for(int i=bottom;i>=top;i--)
            ans.push_back(matrix[i][left]);
            left++;
            }
        }
        return ans;
    }
};

int main()
{
    int rows,cols;
    cout<<"Enter no of rows and columns: ";
    cin>>rows>>cols;

    vector<vector<int>>matrix(rows,vector<int>(cols));
    cout<<"Enter elements:";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        cin>>matrix[i][j];
    }

    Solution obj;
    vector<int>result=obj.spiralOrder(matrix);

    cout<<"Spiral Order:";
    for(int x:result)
    cout<<x<<" ";
    cout<<endl;

    return 0;
}