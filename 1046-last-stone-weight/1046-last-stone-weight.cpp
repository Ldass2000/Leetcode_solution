class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
//         Create a Priority queue (pq)
// as long as size of pq > 1:
// every time pop two elements
// subtract second from first
// if res of subtractions is non-zero push this result back into pq

priority_queue<int> pq;
      for(auto i : stones)        pq.push(i);
      while(pq.size() > 1)
      {
          int a = pq.top(); pq.pop();
          int b = pq.top(); pq.pop();
          if(a  - b > 0)
              pq.push(a-b);
      }
      return pq.empty()?0:pq.top();  
    }
};