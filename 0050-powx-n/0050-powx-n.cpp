class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // Use long long to handle the edge case for n = -2147483648
        
        if (nn < 0) {
            nn = -nn; // Make nn positive
            x = 1 / x; // Invert x for negative powers
        }
        
        while (nn > 0) {
            if (nn % 2 == 1) {
                ans *= x; // Multiply ans by x if the current power is odd
            }
            x *= x; // Square x
            nn /= 2; // Reduce nn by half
        }
        
        return ans;
    }
};
