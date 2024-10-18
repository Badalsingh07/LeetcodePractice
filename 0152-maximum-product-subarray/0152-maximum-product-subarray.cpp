class Solution {
public:

    int maxProduct(vector<int>& nums) {
    int n=nums.size();
    int pre=1;
    int suf=1;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
      if(pre==0)pre=1;
      if(suf==0)suf=1;
      
            pre=pre*nums[i];
            suf=suf*nums[n-1-i];
            mx=max(mx,max(pre,suf));
        }

      return mx;
        
        
        
    }
};