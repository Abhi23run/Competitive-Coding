class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& pts) {
        sort(pts.begin(),pts.end());
        int n=pts.size();
        if(n==0) return 0;
        int x=pts[0].first,y=pts[0].second;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(pts[i].first<=y){
                x=pts[i].first;
                y=min(pts[i].second,y);
            }
            else{
                x=pts[i].first;
                y=pts[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};