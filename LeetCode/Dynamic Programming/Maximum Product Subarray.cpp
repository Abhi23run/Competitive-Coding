class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int dp[n][2];
        int max_prod=INT_MIN;
        dp[0][0]=max(a[0],0);
        dp[0][1]=min(a[0],0);
        max_prod=a[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0]*a[i],max((dp[i-1][1]*a[i]),a[i]));
            dp[i][1]=min(dp[i-1][1]*a[i],min((dp[i-1][0]*a[i]),a[i]));
            max_prod=max(dp[i][0],max_prod);
        }
        return max_prod;
    }
};