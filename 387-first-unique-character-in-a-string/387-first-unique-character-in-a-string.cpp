class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>frq(26,0);
        
        //store frequency of each characters
        for(int i=0;s[i]!='\0';i++)
        {
            frq[s[i]-'a']+=1;
        }
        
          //now traverse and find the first non repeating char
         for(int i=0;s[i]!='\0';i++)
         {
             if(frq[s[i]-'a']==1) return i;
         }
        
        return -1;
    }
};