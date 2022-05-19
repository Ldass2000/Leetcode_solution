class Solution {
public:
    int dp[201][201];
    int dfs(vector<vector<int>> &mat, int i, int j, int pre) {
	//check node is valid or not and also increasing
        if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || pre >= mat[i][j])
            return 0;
        if (dp[i][j]) return dp[i][j];
		// find solution in every possible direction
		//1.left
        int l = dfs(mat, i, j - 1, mat[i][j]);
		//right
        int r = dfs(mat, i, j + 1, mat[i][j]);
		//up
        int u = dfs(mat, i - 1, j, mat[i][j]);
		//down
        int d = dfs(mat, i + 1, j, mat[i][j]);
		//if any path is possible then increase its by one 
        return dp[i][j] = max({l, r, u, d}) + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxVal = 0;
		// we must check every node because any node should be our starting node
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
			//store max value
                maxVal = max(maxVal, dfs(matrix, i, j, -1));
        return maxVal;
    }
};