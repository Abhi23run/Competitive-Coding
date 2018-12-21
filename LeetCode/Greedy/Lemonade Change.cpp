class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int store=0;
        int count5=0;
        int count10=0;
        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                count5++;
            }
            if(bills[i]==10)
            {
                if(count5<=0){
                    return false;
                }
                else
                {
                    count5--;
                    count10++;
                }
            }
            if(bills[i]==20)
            {
                if(count5<=0 || store<15)
                    return false;
                else
                {
                    if(count10>0)
                    {
                        count5--;
                        count10--;
                    }
                    else if(count10==0)
                    {
                        count5-=3;
                    }
                }
                
            }
            store=5*count5+10*count10;
            
        }
        return true;
    }
};