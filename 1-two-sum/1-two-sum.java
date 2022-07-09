class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] ans=new int [2];
        
        Map<Integer,Integer>mp=new HashMap<Integer,Integer>();
        
        for(int i=0;i<nums.length;i++)
        {
           if( mp.containsKey(target-nums[i]))
           {
               ans[1]=i;
               ans[0]=mp.get(target-nums[i]);
               return ans;
           }
            mp.put(nums[i],i);
        }
        
        return ans;
    }
}