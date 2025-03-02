class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
    for(int i = 0, j = 0; i < nums.size(); ++i){
        if(i + 1 < nums.size() && nums[i] == nums[i+1]) { 
            nums[i] = nums[i]*2;
            nums[i+1] = 0;
        }
        if(nums[i] != 0) nums[j++] = nums[i]; 
        if(j <= i) nums[i] = 0;
    }
    return nums;
}
};