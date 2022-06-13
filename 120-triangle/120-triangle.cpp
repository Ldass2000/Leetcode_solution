class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int row=triangle.size()-2;row>=0;row--)
        {
            for(int i=0;i<triangle[row].size();i++)
            {
                triangle[row][i]+=min(triangle[row+1][i],triangle[row+1][i+1]);
            }
        }
        
        return triangle[0][0];
    }
};