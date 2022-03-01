class Solution {
public:
    
    
//     Intuition:
// Indirectly we are told to check if a number is present in the array or not.

// It's only possible in three ways:
// I can check every time from starting.
// I sort the numbers from left to right , I will always get cnt*2 in forward direction and not backward.
// I can use lookup for storing numbers and just see if present or not.
// The last one is more efficient in terms of time.

// Useful Trick:
// Wherever we see there is a need of lookup, we using hashing.
// Like in this Question we are told to check if cnt is present or not.
    
     //Time - O(N)
    //Space- O(N)
    int findFinalValue(vector<int>& nums, int cnt){
    unordered_set<int> s(begin(nums),end(nums));   
    for(;true;)
        if(s.count(cnt)) cnt*=2;
        else break;    
    return cnt;
}
    
    
    
    //Sorting
    //Time Com - O(NlogN)
    //Space Co.. - O(1) { Ignoring Space in sorting }
    
    int findFinalValue(vector<int>& nums, int original) {
         sort(begin(nums),end(nums));
         for(auto i:nums) if(i==original) original*=2;
         return original;
    }
    
    
 //Brute Force:
//Time Com - O(N*no. of times count found)
 //Space Co.. - O(1)
    
    int findFinalValue(vector<int>& nums, int cnt){
   for(auto i=0;i<nums.size();i++)
       if(nums[i]==cnt) cnt*=2,i=-1;
   return cnt;
}
    
    
   

};
