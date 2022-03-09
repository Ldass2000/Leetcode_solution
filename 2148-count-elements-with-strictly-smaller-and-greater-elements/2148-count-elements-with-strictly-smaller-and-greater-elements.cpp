class Solution {
public:
    int countElements(vector<int>& nums) {
        // Find the max and min element of array, store in M and m variables
        // Compare each element with Min and Max and count while iterating through array in O(N) time
        // Return the count as result.
        // Space Complexity: O(1)
        // Time Complexity: O(N)
        
        int M=*max_element(nums.begin(),nums.end());
        int m=*min_element(nums.begin(),nums.end());
        
         int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>m && nums[i]<M)
                ans++;
        }
        return ans;
    }
};