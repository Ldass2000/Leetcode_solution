class Solution {
    public boolean isAnagram(String s, String t) {
        // The idea is simple. It creates a size 26 int arrays as buckets for each letter in alphabet.
        // It increments the bucket value with String s and decrement with string t. So if they are 
        // anagrams, all buckets should remain with initial value which is zero. So just checking that and return
        
        int[] ans= new int[26];
        
        for(int i=0;i<s.length();i++)
        {
            ans[s.charAt(i)-'a']++;
        }
        
        for(int i=0;i<t.length();i++)
        {
            ans[t.charAt(i)-'a']--;
        }
        
        
        for(int i:ans)
        {
            if(i!=0) return false;
        }
        
        return true;
    }
}