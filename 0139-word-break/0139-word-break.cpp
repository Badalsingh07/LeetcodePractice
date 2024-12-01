class Solution {
public:
unordered_set<string>st;
int n;
int dp[301];
bool solve(int idx,string s){
    int n=s.size();
    if(idx>=n)
    return true;
    if(dp[idx]!=-1)
    return dp[idx];

    if(st.find(s)!=st.end())
    return true;
    for(int i=0;i<n;i++){
        string temp=s.substr(idx,i);
        if(st.find(temp)!=st.end() && solve(idx + i,s))
        return dp[idx]=true;
    }
    return dp[idx]=false;
}

    bool wordBreak(string s, vector<string>& word) {
        memset(dp,-1,sizeof(dp));
        for(string &i: word)
          st.insert(i);
          return solve(0,s);
        
    }
};