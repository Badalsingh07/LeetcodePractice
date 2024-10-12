class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max1 = INT_MAX;
        int max2 = INT_MAX;
        for(int n : nums) {
            if(n <= max1) {
                max1 = n;  // Update first minimum
            } else if(n <= max2) {
                max2 = n;  // Update second minimum
            } else {
                return true;  // Found a third number greater than both
            }
        }
        return false;  // No triplet found
    }
};