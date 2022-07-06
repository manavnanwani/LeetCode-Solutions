class Solution {
public:
    int memo[31] = {0};
    int fib(int n) {
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // return fib(n-1) + fib(n-2);
        
        if(n <= 1)
            return n;
        if(memo[n])
            return memo[n];
        return memo[n] = fib(n-1) + fib(n-2);
    }
};