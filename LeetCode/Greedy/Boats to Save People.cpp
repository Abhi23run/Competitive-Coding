class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int start=0;
        int end=n-1;
        int ans=0;
        while(start<=end)
        {
            ans+=1;
            if((people[start]+people[end])<=limit)
            {
                start++;
            }
            end--;
        }
        return ans;
    }
};