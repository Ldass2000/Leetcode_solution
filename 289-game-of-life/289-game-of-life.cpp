class Solution {
public:
    
//     we are Interested in only live cells i.e 1,So dead cells i.e 0 can be changed to any number.
// Algorthim
// 1.Iterate over the gird
// 2.Find the no of neighbour live cells for the particular cell.
// 3.Let neighbour live cells be Nlive;
// If current cell is live i.e 1

// Check for Condition (Nlive <2 || Nlive > 3)
// If it holds then live cell should die, else it would be alie.
// Suppose condition satisfied then assign -1 to current cell
// Indicating that the cell is died.
// Condition Not satisfied. Leave it undistrubed
// If current cell is dead

// Check for Condition (Nlive == 3) .
// If condition met then dead cell should become alive.
// Suppose conditon met, that mean cell should be alive.
// Assign 2 to dead cell, indicating that it is intially dead cell and is alive now.
// IF condition not met.
// Assign -2 to dead cell,indicating the cell is dead state only.
// 4.Convert all the Negative to zero and Positive numbers to 1

// It Might be difficult to understand, I Tried my best to explain. Dry run it, Definitely you will understand it.
    
    
    
//     Time Complexity -- O(M*N)
// Space Complexity -- O(1)
    
    
    int LiveCells(vector<vector<int>> &board,int i,int j,int m,int n)
    {
        int xx[8] = {0, 0,1,-1,1,1,-1,-1};
        int yy[8] = {1,-1,0,0,-1,1,1,-1};
        int live = 0 ;
        for(int k=0; k<8; k++)
        {
            int x = i + xx[k], y = j + yy[k];
            if(x>=0 && x < m && y>=0 && y<n && abs(board[x][y]) == 1)
                live++;
        }
        return live;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
          /*In Place Solution*/
        int m = board.size(),n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int live = LiveCells(board,i,j,m,n);
                if(board[i][j])
                   board[i][j] = (live <2 || live > 3) ? -1 : 1;
                else
                   board[i][j] = (live == 3) ? 2 : -2; 
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                board[i][j] = (board[i][j] > 0) ? 1 : 0;
        } 
    }
};