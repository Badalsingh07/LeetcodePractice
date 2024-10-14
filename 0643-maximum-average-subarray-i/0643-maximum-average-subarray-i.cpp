class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0 ;
        for(int i = 0 ; i < k ; i++){
            sum += nums[i];
        }

        int maxSum = sum;
        int Start_idx = 0 ;

        int End_idx = k;

        while(End_idx < nums.size()){
            sum -= nums[Start_idx];
            Start_idx++; 

            sum += nums[End_idx];
            End_idx++;

            maxSum = max(sum , maxSum); 
        }
        return (double) maxSum/k; 
    }
};