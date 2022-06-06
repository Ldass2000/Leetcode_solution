class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long long root=sqrt(c);
        
        long long l=0,h=root;
        
        while(l<=h)
        {
            if((l*l + h*h)< c) l++;
            else if((l*l+h*h)>c) h--;
            else return true;
        }
        
        return false;
    }
};