class Solution {
public:
    /* int solveUsingMem(int n,vector<int>dp){

        //base case 
        if(n==0||n==1)
        return 1;
        //step2
        if(dp[n]!=-1){
            return dp[n];
        }
        //step3
        dp[n]=solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
        return dp[n];
     }*/
 
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
            dp[0]=1;
            dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
        
    }
};