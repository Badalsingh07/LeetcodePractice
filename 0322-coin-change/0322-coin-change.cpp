class Solution {
public:
    int solve(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0)return target/coins[0];
             return 1e9;
        }
       if(dp[ind][target] != -1) 
            return dp[ind][target];
        int notTake=solve(ind-1,target,coins,dp);
        int take=INT_MAX;
        if(target>=coins[ind])take=1+solve(ind,target-coins[ind],coins,dp);
        return dp[ind][target]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
     // memo
     int n=coins.size();
    //  vector<vector<int>>dp(n,vector<int>(amount+1,0));
    //  int ans= solve(n-1,amount,coins,dp);
    //  if(ans>=1e9)return -1;
    //  return ans;
    vector<int>prev(amount+1,0);
    vector<int>curr(amount+1,0);
    for(int t=0;t<=amount;t++){
        if(t%coins[0]==0)prev[t]=t/coins[0];
        else prev[t]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=amount;target++){
            int notTake=prev[target];
        int take=INT_MAX;
        if(target>=coins[ind])take=1+curr[target-coins[ind]];
        curr[target]=min(take,notTake);
        }
        prev=curr;
    }
    int ans=prev[amount];
    if(ans>=1e9)return -1;
    return ans;
    }
};