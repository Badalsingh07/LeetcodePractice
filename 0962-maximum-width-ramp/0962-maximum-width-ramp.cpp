class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        if(n==2)
        {
            if(nums[1]>=nums[0])
            return 1;
            else
            return 0;

        }
        int start=0;
        int end=start+1;
        int mx=INT_MIN;
        int sub=0;
        for(int i=0;start<=n-2;i++){
            if(nums[end]>=nums[start])
              sub= end-start;
            if(sub>=mx && sub>0)
              mx=sub;
            if(end==n-1){
               start++;
               end= start;
            }
            

            end++;
             sub=0;



        }if(mx>=0)
        return mx;
        else 
        return 0;

        
    }
};