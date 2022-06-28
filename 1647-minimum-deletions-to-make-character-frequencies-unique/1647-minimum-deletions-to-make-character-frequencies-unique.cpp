class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        
         // insert all elements in map
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        
        int ans=0;
        
         // set to have count of frequencies of each element , we can also use map or vector
        set<int>st;
        
        for(auto[i,j]:mp)
        {
            while(st.find(j)!=st.end())    //   if we've seen the count of char  before, decrement it until we haven't
            {
                j--;
                ans++;
            }
            
             // if this frequency has not been encountered before we will insert it in stack  
            if(j>0)
            {
                st.insert(j);
            }
        }
        
        return ans;
    }
};