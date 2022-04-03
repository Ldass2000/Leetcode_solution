class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int sz = nums.size();
        int k=-1;
        int l;
        //step1
        for (int i=0;i<sz-1;i++){
            if (nums[i]<nums[i+1]){
                k=i;
            }
        }
        if (k==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        
        //step2
        for (int i=k+1;i<sz;i++){
            if (nums[i]>nums[k]){
                l=i;
            }
        }
        //step3        
        int tmp = nums[l];
        nums[l]=nums[k];
        nums[k]=tmp;
        //step4
        reverse(nums.begin()+k+1,nums.end());
    }
};