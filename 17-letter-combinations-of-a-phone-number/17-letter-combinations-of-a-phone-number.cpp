class Solution {
public:
    unordered_map<int,vector<char>>digit_letter;
    vector<int>nums;
    vector<string>LetterCombination;
    void totalCombination(int pos,string curr_word)
    {
        vector<char>letters=digit_letter[nums[pos]];
        for(auto ch:letters)
        {
            if(pos==nums.size()-1)
            {
                LetterCombination.push_back(curr_word+ch);
            }
            else
            {
                totalCombination(pos+1,curr_word+ch);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        digit_letter[2]={'a','b','c'};
        digit_letter[3]={'d','e','f'};
        digit_letter[4]={'g','h','i'};
        digit_letter[5]={'j','k','l'};
        digit_letter[6]={'m','n','o'};
        digit_letter[7]={'p','q','r','s'};
        digit_letter[8]={'t','u','v'};
        digit_letter[9]={'w','x','y','z'};
                         
                         
                         
      if(digits.size()==0)
      {
          return {};
      }
                         
        for(auto d:digits)
        {
            nums.push_back(d-'0');
        }
                         
       totalCombination(0,"");
       return  LetterCombination;
    }
};