/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a,Interval b)
{
    if(a.start!=b.start)
        return a.start<b.start;
    else
        return a.end<=b.end;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<=1)
            return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int x=intervals[0].start;
        int y=intervals[0].end;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(intervals[i].start>=x and intervals[i].start<y)
            {
                x=intervals[i].start;
                y=min(intervals[i].end,y);
            }
            else
            {
                x=intervals[i].start;
                y=intervals[i].end;
                cnt++;
            }
        }
        return (n-cnt);
    }
};