class Solution {
public:
    int longestValidParentheses(string s) {
         int n = s.length();
        
        //stack to store indices of '('
        stack<int>st;
        
        //'-1' mark the starting point of stack of a valid sub string
        st.push(-1);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            //if opening bracket then ,push it's index
            if(s[i]=='(')
                st.push(i);
            else
            {
                //pop previous '(' index
                if(!st.empty())
                    st.pop();
                
                //length of valid sub string till now
                
                if(!st.empty())
                    ans=max(ans,i-st.top());
                else
                {
                    //mark the begining of next valid substring 
                    st.push(i);
                }
            }
        }
        return ans;
    }
};