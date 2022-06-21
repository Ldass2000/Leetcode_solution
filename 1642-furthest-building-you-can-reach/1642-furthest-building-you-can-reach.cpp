
// Keep a priority queue of the same size as ladders.

// add positive diffs to pq

// Once the pq gets bigger than the ladders, pop the top, and add that popped to the "brick sum".

// This idea works because we want to use ladders for the largest diffs that we see.

// k = number of ladders

// Time Comlexity: O(N log k)
// Space Complexity: O(k)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         priority_queue<int, vector<int>, greater<int>> pq;
          int n = heights.size();
        int brickSum = 0;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff <= 0) continue;
            
            pq.push(diff);
            if(pq.size() > ladders) {
                brickSum += pq.top();
                pq.pop();
            }   
            if(brickSum > bricks) return i - 1;
        }
        return n-1; 
    }
};