class Solution {
public:
    
    bool KyaMacthhoga(string word,string pat)
    {
        unordered_map<char,char>patmap;
        unordered_map<char,char>wordmap;
        
        for(int i=0;i<pat.size();i++)
        {
            if(wordmap.find(word[i])==wordmap.end())
            {
                wordmap[word[i]]=pat[i];
            }
            
            if(patmap.find(pat[i])==patmap.end())
            {
                patmap[pat[i]]=word[i];
            }
            
            if(wordmap[word[i]]!=pat[i]|| patmap[pat[i]]!=word[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        
        for(int i=0;i<words.size();i++)
        {
            if(KyaMacthhoga(words[i],pattern))
            {
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
};