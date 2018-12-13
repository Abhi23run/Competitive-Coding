class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int max_area=INT_MIN;
        while(l<r)
        {
            max_area=max(max_area,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])
        {
            l++;
        }
            else
            {
                r--;
            }
        }
        return max_area;
        
    }
};