class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==0)
        {
            return 0;
        }
        int cash,cash1,hold1;
        int hold;
        cash=0;
        hold=-prices[0];
        for(int i=1;i<n;i++)
        {
            cash1=max(cash,hold+prices[i]-fee);
            hold1=max(hold,cash-prices[i]);
            cash=cash1;
            hold=hold1;
        }
        return cash;
    }
};