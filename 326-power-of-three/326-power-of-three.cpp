class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        double x = log10(n) / log10(3);
        double f = floor(x), c = ceil(x);
        return f == c ? true : false;
    }
};