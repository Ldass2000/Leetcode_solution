class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
         int count= 0;
        for(int i=1;i<nums.size();i++){
            // case for checking count
            if(nums[i-1] > nums[i]){
                
                // at max, we can have one count. So if it has been occured before => return false
                if(count == 1){
                    return false;
                }
                //if no previous count, then count++
                count++;
               
                // fixing count => operation 1
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                // fixing count => operation 2
                else
                    nums[i] = nums[i-1];
                
            }
        }
        // if traversal of vector was successfull and return statement was not invoked then return true.
        return true;
    }
};