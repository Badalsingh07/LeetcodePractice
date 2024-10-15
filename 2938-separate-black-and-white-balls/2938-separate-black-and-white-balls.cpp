class Solution {
public:
    long long minimumSteps(string nums) {
        
        int n=nums.size();
     
        long long int count=0;
         long long  int swp=0;
        
       
     
        for(long long int i=0;i<n;i++){
            if(nums[i]=='1')
               count+=1;
               if(nums[i]=='0')
               swp+=count;
                  
        }  
         return swp;  
        
       
    }
};