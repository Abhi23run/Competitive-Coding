class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        vector<int>prev(256,-1);
        prev[s[0]]=0;
        int cur_len=1;
        int max_len=1;
        int prev1;
        for(int i=1;i<n;i++)
        {
            prev1=prev[s[i]];
            if(prev1==-1 || i-cur_len>prev1)
                cur_len++;
            else
            {
                max_len=max(max_len,cur_len);
                cur_len=i-prev1;
            }
            prev[s[i]]=i;
        }
        max_len=max(max_len,cur_len);
        return max_len;
    }
};