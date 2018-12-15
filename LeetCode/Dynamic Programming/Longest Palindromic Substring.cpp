class Solution {
public:
    string longestPalindrome(string s) {
        int result=0;
        string ans="";
        int n=s.length();
        if(n==0)
        {
            return ans;
        }
        bool dp[n][n]={0};
        int start=0;
        int maxlen=1;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i+1]==s[i])
            {
                dp[i][i+1]=1;
                start=i;
                maxlen=2;
            }
        }
        for(int l=3;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                if(dp[i+1][j-1] && s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(l>maxlen)
                    {
                        start=i;
                        maxlen=l;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};