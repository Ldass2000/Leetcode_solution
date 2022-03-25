class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Compute the cost of sending every person to City A and also calculating the diff of 
       //both cities, & Now pick N persons which has least diff and send them to City B
        
        vector<int>ans;
        int mincost=0;
        for(int i=0;i<costs.size();i++)
        {
            mincost+=costs[i][0];
            ans.push_back(costs[i][1]-costs[i][0]);
        }
        
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<costs.size()/2;i++)
        {
            mincost+=ans[i];
        }
        return mincost;
    }
};