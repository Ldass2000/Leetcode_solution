class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//          Idea :
//            Linked list Cycle II
               
//                since we have a duplicate  number,then if we make a list from the given numbers
//                we can see a cycle preseent in it. and the starting point of cycle will be duplciate 
//                    mumber
        //TC-->O(n)
        
        int slow=nums[0];
        int fast=nums[0];
        
        //finding cycle
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        
        
        //finding starting point
        
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }
};