class Solution {
    public int tribonacci(int n) {
        int a=0,b=1,c=1,d=0;
        
        for(int i=0;i<n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            d=a;
        }
        
        
        return d;
    }
}