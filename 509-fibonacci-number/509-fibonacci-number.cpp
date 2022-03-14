class Solution {
public:
    int fib(int n) {
        
        //  //TC-->O(n^2),sc-->O(n)
        //  if(n==0) return 0;
        //   if(n==1) return 1;
        // return fib(n-1)+fib(n-2);
        
        
        //Tc-->O(n),sc-->O(1)
        if(n<2) return n;
        int a=0,b=1,c=0;
        for(int i=1;i<n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};