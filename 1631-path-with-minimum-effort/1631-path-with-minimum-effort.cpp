class Solution {
    
    
//     Dijkstra's Approach :

// Aim : To find that path where we'll spend minimum effort.
// Minimum effort according to question is the maximum of absolute difference between any two consecutive heights in that path.

// Process :

// Create a priority_queue pq (min heap) to store {effort, {x, y}} in that order.

// Create a 2d vector eff and initialize it with inf, to keep track of minimum effort found so far.

// As we're starting at (0, 0), Initialize eff[0][0] = 0, (i.e. no effort required to go from 0,0 -> 0,0).

// Push {eff[0][0], {0, 0}} into priority queue.

// From {0, 0} traverse to all valid indices, keep track of maximum absolute difference in that path in maxAbs.

// For example, from {0, 0} we can go to {0, 1} & {1, 0}.
// Intially effort = 0.
// consider {0, 1}, effort required to go from {0, 0} to {0, 1}, let's say it current_effort = abs(height[0][1] - height[0][0]). Store max(effort, current_effort) into maxAbs.
// if this maxAbs is less than eff[0][1], than for now this path will give the minimum effort. So to keep track of this path push it in pq as {maxAbs, {0, 1}}.
// otherwise, there already exist a path with minimum effort so we dont need to keep track of this path.

// Once we reach (m-1, n-1) simply return effort.
    
private:
    const int inf = 1e6+5;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    bool isValid(int index, int lim) {
        return (index >= 0 && index < lim);
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> eff(m, vector<int>(n, inf));
        eff[0][0] = 0;
        pq.push({eff[0][0], {0, 0}});
        while(!pq.empty()){
            int effort = (-1) * pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == m-1 && y == n-1) return effort;
            for(int k=0; k<4; k++){
                int i = x+dx[k];
                int j = y+dy[k];
                if(isValid(i, m) && isValid(j, n)){
                    int maxAbs = max(effort, abs(heights[i][j] - heights[x][y]));
                    if(maxAbs < eff[i][j]){
                        eff[i][j] = maxAbs;
                        pq.push({(-1) * eff[i][j], {i, j}});
                    }
                }
            }
        }
        return -1;
    }
};