class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
        {
            return 0;
        }
        int dp[n]={0};
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(prices[j]<prices[i])
                {
                    dp[i]=max(dp[i],prices[i]-prices[j]);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};