bool isPal(string st,int lo,int hi)
{
    while(lo<hi)
    {
        if(st[lo]!=st[hi])
            return 0;
        lo++;
        hi--;
    }
    
    return 1;
}

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
                dp[i][i+1]=1;
            else
                dp[i][i+1]=0;
        }
        for(int l=3;l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int j=i+l-1;
                if(isPal(s,i,j))
                    dp[i][j]=0;
                else
                {
                    int min1=dp[i][i]+dp[i+1][j];
                    for(int k=i+1;k<j;k++)
                    {
                        if(dp[i][k]+dp[k+1][j]<min1)
                        {
                            min1=dp[i][k]+dp[k+1][j];
                        }
                    }
                    dp[i][j]=1+min1;
                }
            }
        }
        return dp[0][n-1];
        
    }
};