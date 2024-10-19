class Solution {
public:
    // Helper function to invert a bit: '0' -> '1' and '1' -> '0'
    char invert(char bit) {
        return (bit == '0') ? '1' : '0';
    }

    // Recursive function to find the k-th bit in S(n)
    char findKthBit(int n, int k) {
        // Base case: S(1) = "0"
        if (n == 1) return '0';

        int length = (1 << n) - 1; // Length of S(n) is 2^n - 1
        int mid = length / 2 + 1;  // Middle bit position

        if (k == mid) {
            return '1'; // Middle bit is always '1'
        } else if (k < mid) {
            return findKthBit(n - 1, k); // Search in the first half (S(n-1))
        } else {
            // Search in the second half (reversed and inverted part)
            char mirroredBit = findKthBit(n - 1, length - k + 1);
            return invert(mirroredBit);
        }
    }
};
