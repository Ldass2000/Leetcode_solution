class Solution {
    private:
    
      bool isPalin(int i,int j,string s)
      {
          while(i<=j)
          {
              if(s[i]!=s[j]) return false;
              i++;
              j--;
          }
          return true;
      }
public:
    bool validPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        
        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                if(isPalin(start+1,end,s) or isPalin(start,end-1,s))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            start++;
            end--;
        }
        return true;
    }
};