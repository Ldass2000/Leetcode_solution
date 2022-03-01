class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
         sort(begin(nums),end(nums));
         for(auto i:nums) if(i==original) original*=2;
         return original;
    }
};