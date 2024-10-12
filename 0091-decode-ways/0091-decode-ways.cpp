class Solution {
    int solve(string &s, vector<vector<int>>&dp,int i,int j){
        if(j>=s.size())
        return 0;
        if(s[i]=='0' )
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s[i]-'0'>0){
             int include=(1+solve(s,dp,i+1,j+1));
             int exclude=(0+solve(s,dp,i,j+1));
             dp[i][j]=max(include,exclude);

                }
          
            return dp[i][j];
         
        }
        
   
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int ans=solve(s,dp,0,0);
        return ans;
        
    }
};