class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // vector<int>ans;
        
        unordered_map<int,int>mp;
        
        for(int i:nums)
        {
           mp[i]++;
        }
        
        
        for(auto dass:mp)
        {
            if(dass.second==1)
            {
                return dass.first;
            }
        }
        
        return -1;
    }
    
    // Hash Table Algo
   // Time: O(n)
  // Space: O(n)
    
    
};