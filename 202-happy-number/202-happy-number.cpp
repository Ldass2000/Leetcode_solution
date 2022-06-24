class Solution {
public:
    
     int sum_of_seq(int n)
    {
        int res=0;
        while(n)
        {
            res+=(n%10)*(n%10);
            n=n/10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        unordered_set<int>_set;
        while(true)
        {
            if(n==1) return true;
            if(_set.count(n)) return false;
            _set.insert(n);
            n=sum_of_seq(n);
        }
        return false;
    }
};