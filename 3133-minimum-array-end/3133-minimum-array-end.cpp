class Solution {
public:
        long long minEnd(int n, int x) {
        n--;
        long long a = x, b;
        for (b = 1; n > 0; b <<= 1) {
            if ((b & x) == 0) {
                a |= (n & 1) * b;
                n >>= 1;
            }
        }
        return a;
    }
};