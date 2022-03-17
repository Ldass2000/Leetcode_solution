class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
//          We take two variable left as "l" and right as "r" we intialize left as zero and right as the nums.size( )-1 (the last value of array ) ans start the loop until left is smaller than right.
// we check that nums[left] is a odd and then check for nums[right] is even if yes then swap them else we will check whether nums[right] is odd if yes then we didn't want it so decrement right by one and do same with left first check whether the left element is even if yes then ignore it and increment left by one after that we will find a position where nums[left] and nums[right] both statisfy the condition we will swap them
        
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]%2!=0 && nums[r]%2==0){
                int temp=nums[l];
                nums[l]=nums[r];
                nums[r]=temp;
                l++;
                r--;
            }
            else if(nums[r]%2!=0){
                r--;
            }
            else if(nums[l]%2==0){
                l++;
            }
        }
        return nums;
    }
};