class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
        {
            return 0;
        }
        int i=0;
        int max_prof=0;
        int peak=prices[0],val=prices[0];
        while(i<n-1)
        {
            while(i<n-1 && prices[i]>=prices[i+1])
            {
                i++;
            }
            val=prices[i];
            while(i<n-1 && prices[i]<=prices[i+1])
            {
                i++;
            }
            peak=prices[i];
            max_prof+=peak-val;
        }
        return max_prof;
    }
};