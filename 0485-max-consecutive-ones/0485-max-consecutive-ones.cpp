class Solution {
public:

    int findMaxConsecutiveOnes(vector<int>& a) {
        int s = 0;  // Current streak of consecutive 1s
        int mS = 0; // Maximum streak of consecutive 1s
        int n = a.size();
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                s++;            // Increment the streak if the current element is 1
                mS = max(mS, s); // Update the maximum streak
            } else {
                s = 0;          // Reset the streak if the current element is not 1
            }
        }
        return mS; // Return the maximum streak found
    }
};
