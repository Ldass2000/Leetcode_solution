class Solution {
public:
    static bool comp(vector<int>&box1, vector<int>&box2)
    {
        return box1[1]>box2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        int units=0;
        
        for(auto it:boxTypes)
        {
            if(it[0]<=truckSize)
            {
                units+=(it[0]*it[1]);
                truckSize-=it[0];
            }
            else
            {
              units+=(truckSize *it[1]);
                truckSize=0;
            }
        }
        
        return units;
    }
};