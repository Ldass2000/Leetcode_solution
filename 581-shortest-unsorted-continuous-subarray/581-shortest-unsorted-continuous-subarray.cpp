class Solution {
public:
    
//     First we need to find the elements who are not following the ascending order and lets for the sake of understanding call them imposter elements.
// We need to find the min and max of these imposter elements and i have stored the smaller imposter element in mi and largest in ma.
// Then i will be iterating from start to find which element is bigger than my mi and the point i get that element i can say that my mi belongs to that particular spot so i will put a start variable over there 
        
    int findUnsortedSubarray(vector<int>& nums) {
        int i;
        int mi=INT_MAX;
        int ma=INT_MIN;
        int n=nums.size();
        for(i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                mi=min(mi,nums[i+1]);
            }
        }
        if(mi==INT_MAX){return 0;}
        for(i=n-1;i>0;i--)
        {
            if(nums[i]<nums[i-1])
            {
                ma=max(ma,nums[i-1]);
            }
        }
        int start,end=n-1;
        for(i=0;i<n;i++)
        {
            if(nums[i]>mi)
            {
                start=i;
                break;
            }
        }
        for(i=n-1;i>=0;i--)
        {
            if(nums[i]<ma)
            {
                end=i;
                break;
            }
        }
        return end-start+1;
    }
};