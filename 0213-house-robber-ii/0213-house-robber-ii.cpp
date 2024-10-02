class Solution {
public:
    int solve(vector<int> &nums, int st, int e){
        
        int prev = nums[st], prev1 = 0;

        for(int i = st+1; i <= e; i++){
            int dont_take = prev;
            int take = prev1+nums[i];
            prev1 = prev;
            prev = max(dont_take, take);
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));    
    }
};
