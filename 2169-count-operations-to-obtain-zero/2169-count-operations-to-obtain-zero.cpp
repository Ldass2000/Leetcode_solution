class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0) return 0;
        if(num1 == num2) return 1;
        if(num1 > num2) return countOperations(num1-num2, num2)+1;
        else return countOperations(num1, num2-num1)+1;
    }
};