#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int m=mat.size();
       int n=mat[0].size();

       if(m*n != r*c)
       return mat;
       vector<vector<int>>ans(r,vector<int>(c));
       int row=0,col=0;
       for(int i=0;i<m;i++)
       {
            for(int j=0;j<n;j++)
            {
                ans[row][col]=mat[i][j];
                col++;
                if(col==c)
                {
                    row++;
                    col=0;
                }
            }
       }
        return ans;
    }
};

int main()
{
    int m,n;
    cout<<"Enter rows and cols of matrix:";
    cin>>m>>n;

    vector<vector<int>>mat(m,vector<int>(n));
    cout<<"Enter matrix elements:";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>mat[i][j];
    }

    int r,c;
    cout<<"Enter rows and cols of matrix:";
    cin>>r>>c;

    Solution obj;
    vector<vector<int>>res=obj.matrixReshape(mat,r,c);

    cout<<"Reshaped Matrix:";
    for(auto &row:res){
        for(int val:row)
        cout<<val<<" ";
        cout<<endl;
    }

    return 0;
}
