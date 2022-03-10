class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=nums[0];
        int mx,mi;
        mx=prod;
        mi=prod;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(mx,mi);
            }
            mx=max((int)nums[i],mx*nums[i]);
            mi=min((int)nums[i],mi*nums[i]);
            prod=max(prod,mx);
        }
        return prod;
    }
};