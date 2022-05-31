class Solution {
public:
    int scoreOfParentheses(string s) {
        //Aproach 1
//         stack<int>st;
//         int score=0;
        
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='(')
//             {
//                 st.push(score);
//                 score=0;
//             }
            
//             else
//             {
//                 score=st.top()+max(2*score,1);
//                 st.pop();
//             }
//         }
        
        // return score;
        
        //SC-->O(N),TC-->O(N)
        
        
        //Approach 2
        
        // SC-->O(1)
        
//         We count the number of layers.
// If we meet '(' layers number l++
// else we meet ')' layers number l--

// If we meet "()", we know the number of layer outside,
// so we can calculate the score res += 1 << l.
        
        int ans=0,l=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') l++;
            else l--;
            
            if(s[i]==')' && s[i-1]=='(') ans+=1<<l;
        }
        
        return ans;
    }
};