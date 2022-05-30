class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        
        //Edge-case , return an empty vector if nums is empty
        if(nums.empty())  return ans;
        
         // sort numbers, n log n
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
             // if nums[i] is larger than zero, we're out of potential combinations
              if(nums[i]>0) return ans;
            
              // skip if we already processed this number
             if(i>0 and nums[i]==nums[i-1]) continue;
            
              
            // now that one of the numbers is fixed (nums[i])
            // we can find matches using a sliding window
            
            int left=i+1;
            int right=n-1;
            
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                
                if(sum>0) right--;
                else if(sum<0) left++;
                
                else
                {
                    // we've got a match
                    
                    ans.push_back({nums[i],nums[left],nums[right]});
                    
                    
                    // to avoid duplicates, we need to skip numbers
                    // we already processed
                    
                    while(left<right && nums[left]==nums[left+1]) left++;
                    
                    while(left<right && nums[right]==nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
            }
        }
        
        
        return ans;
    }
};