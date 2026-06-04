#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {   
            sum+=mat[i][i];
            sum+=mat[i][n-1-i];
        }
        if(n%2==1)
        sum-=mat[n/2][n/2];
        return sum;
    }
};

int main()
{
    int n;
    cout<<"Enter size of the matrix :";
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));

    cout<<"Enter elements :";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>mat[i][j];
    }

    Solution obj;
    cout<<"Diagonal Sum = "<< obj.diagonalSum(mat)<<endl;
    return 0;
}
