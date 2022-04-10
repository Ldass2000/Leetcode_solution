class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        
        for(auto elem:ops)
        {
            if(elem=="+")
            {
                int last=ans[ans.size()-1];
                int secondlast=ans[ans.size()-2];
                
                ans.push_back(last+secondlast);
            }
            
            else if(elem=="D")
            {
                int last=ans[ans.size()-1];
                ans.push_back(last*2);
            }
            
            else if(elem=="C")
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(stoi(elem));
            }
        }
        
        
        int res=0;
        for(auto dass:ans)
            res+=dass;
        
        return res;
        
    }
};