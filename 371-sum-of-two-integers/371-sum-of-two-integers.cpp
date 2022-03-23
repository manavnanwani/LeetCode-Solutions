class Solution {
public:
    int getSum(int a, int b) {
        // return log(exp(a) * exp(b));
        while(b!=0){
            unsigned int temp = (a&b);
            a = a ^ b;
            b = temp << 1;
        }
        return a;
    }
};