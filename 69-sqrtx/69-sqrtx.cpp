class Solution {
public:
    int mySqrt(int x) {
        //Binary search
        long left = 0, right = x, mid = (left + right)/2;
        while(left<=right){
            long ans = mid * mid;
            if(ans == x)
                return mid;
            if(ans<x){
                left = mid + 1;
                mid = (left + right)/2; 
            }
            else{
                right = mid -1;
                mid = (left + right)/2;
            }
        }
        return mid;
    }
};