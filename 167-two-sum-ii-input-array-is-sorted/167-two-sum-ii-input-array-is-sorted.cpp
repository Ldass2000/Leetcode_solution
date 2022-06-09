class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Using the two-pointer approach, first create two pointers one to start off at the 0th index and the other to start from the end of the array.We create a while loop that will keep running provided the first pointer, pointer1, is less than the second pointer,pointer2. Inside this while loop, we find the sum of the elements at the respective pointer positions. If the sum is equal to the target, return those two indices, otherwise, if the sum is less than the target, increase the first pointer position by one and if the sum is greater than the target, reduce the second pointer by 1
        int n=numbers.size();
        int f=0,l=n-1;
        
        while(f<l)
        {
            int temp=numbers[f]+numbers[l];
            
            if(temp==target)
            {
                vector<int>ans{f+1,l+1};
                return ans;
            }
            
            
            if(temp<target)
            {
                f++;
                continue;
            }
            
            if(temp>target)
            {
                l--;
                continue;
            }
        }
        
        
        return numbers;  // won't be reached due to constraints
    }
};