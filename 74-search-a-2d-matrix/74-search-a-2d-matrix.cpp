class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //since each row is sorted and first integer of each row is greater than last integer of the previous row.
        //If the target lies in between first element and last element  of that row we can use binary search to search the         //element
        
         int m=matrix.size();
         int n=matrix[0].size();
         
          for(int i=0;i<m;i++)
          {
              if(matrix[i][0]<=target && target<=matrix[i][n-1])
              {
                  int l=0;
                  int e=n-1;
                  while(l<=e)
                  {
                      int mid=l+(e-l)/2;
                      if(target==matrix[i][mid])
                          return true;
                      else if(target<matrix[i][mid])
                          e=mid-1;
                      else
                          l=mid+1;
                  }
              }
          }
        return false;
    }
};