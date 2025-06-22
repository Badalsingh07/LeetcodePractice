class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int a= nums[0];
        nums.push_back(a);
int maxdiff=0;
       for(int i=0; i<nums.size()-1; i++){
            maxdiff= max(abs(nums[i]- nums[i+1]), maxdiff);


       }
 return maxdiff;
    }
};