class Solution {
public:
//top-down approch
/*
       int solve( string &t1,string &t2,int i,int j, vector<vector<int>>&dp){
        if(i>=t1.length())
        return 0;
        if(j>=t2.length())
        return 0;
        //return dp
        if(dp[i][j]!=-1)
        return dp[i][j];
         //match
         int ans=0;
        if(t1[i]==t2[j])
        ans= (1 + solve(t1,t2,i+1,j+1,dp));
        else
          ans= max( solve(t1,t2,i+1,j,dp), solve(t1,t2,i,j+1,dp));
          return ans;

       }*/

       //tabulation
        int solve( string &a,string &b){
         vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
           
            int ans=0;
             if(a[i]==b[j])
              ans= (1 + dp[i+1][j+1]);
           else
             ans= max( dp[i+1][j], dp[i][j+1]);
             dp[i][j]=ans;

        }
        }
          return dp[0][0];
        }
     

    int longestCommonSubsequence(string text1, string text2) {
        
        int ans=solve(text1,text2);
        return ans;
        
    }
};