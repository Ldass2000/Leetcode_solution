class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int n:nums)
            m[n]++;
        
        for(auto it:m)
            q.push({it.second,it.first});
        
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};