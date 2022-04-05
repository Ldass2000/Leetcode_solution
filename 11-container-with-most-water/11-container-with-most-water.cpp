class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r=n-1;
        int mx=INT_MIN;
        while(l<r)
        {
            int h=min( height[l], height[r]);
            int width=r-l;
            int area=h*width;
            mx=max(mx,area);
            if( height[l]< height[r]) l++;
            else r--;
        }
        return mx;
    }
};