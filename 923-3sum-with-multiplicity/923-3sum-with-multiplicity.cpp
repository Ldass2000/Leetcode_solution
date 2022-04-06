class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9 + 7;
        long ans=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            vector<int> count(101, 0); // array element size
            for(int j=i+1;j<n;j++)
            {
                int k=target-arr[i]-arr[j];
                if(k>=0 && k<=100 && count[k]>0)
                {
                  ans+=count[k];
                  ans%=mod;
                }
                 count[arr[j]]++;
            }
        }
        
        return  (int)ans;
    }
};