class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n - 2; i++) {
            if ((nums[i + 1]) ==( nums[i] + nums[i + 2])*2.0) {
                count++;
            }
        }
        
        return count;
    }
};
