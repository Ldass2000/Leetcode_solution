class Solution {
public:
    string removeDuplicates(string s, int k) {
         stack<pair<int,int>> st;//stack will hold  (index, number of same character before the index including itself)
        int i=0;
        int n=s.size();
        while(i<n)
        {
            if((!st.empty())) //if the stack is non empty
            {
                if(s[st.top().first]==s[i])  //if the current character matches with the character in the top of the stack
                {
                    if(st.top().second+1==k)  //if adding the current character in list , makes a list of size 'k' of same chatacters ,
                                                //then pop all the (k-1) characters in the stack
                    {
                        int temp=k-1;
                        while(temp--)
                        {
                            st.pop();
                        }
                    }
                    else   //if it doesn't make a size of 'k' then push (index, number of same character) pair
                    {
                        st.push({i,st.top().second+1});
                    }
                }
                else  //if the current character doesn't match with the top of the stack character , then push the current character index and number of same character , which is 1 in this case
                {
                    st.push({i,1});
                }
            }
            else //if the stack is empty , push the current character index and number of same character , which is 1 
            {
                st.push({i,1});
            }
            i++;
        }
        
        //the character remained in the stack will form our final string , but it will be in reverse order . So we need to reverse it also
        string str="";
        while(!st.empty())
        {
            str+=s[st.top().first];
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};