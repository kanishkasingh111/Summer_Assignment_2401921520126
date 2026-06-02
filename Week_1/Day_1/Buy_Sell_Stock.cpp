//Best Time to Buy and Sell Stocks

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};

int main(){
    int n;
    cout<<"Enter no of days: ";
    cin>>n;
    vector<int>prices(n);
    cout<<"Enter stock prices: ";
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    Solution obj;
    int ans=obj.maxProfit(prices);
    cout<<"Max Profit: "<<ans<<endl;

    return 0;

}