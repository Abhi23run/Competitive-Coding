class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
        {
            return n;
        }
        int dp[n][2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && 1+dp[j][1]>dp[i][0])
                    dp[i][0]=1+dp[j][1];
                if(nums[j]>nums[i] && 1+dp[j][0]>dp[i][1])
                    dp[i][1]=1+dp[j][0];
            }
        }
        return max(dp[n-1][1],dp[n-1][0]);
    }
};