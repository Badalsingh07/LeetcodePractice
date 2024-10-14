
 #include <cmath>
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
     long long int n= nums.size();
     priority_queue<long long int>pq;
     for(long long int i=0;i<n;i++)  {
        pq.push(nums[i]);

     }      
    
      long long ans=0;
      while(k>0){
        long long  int val= pq.top();
         ans+=val;
        pq.pop();
        long long int res=ceil(val/3.0);
        pq.push(res);
        k--;
  
    }
    return ans;
    }
  
};