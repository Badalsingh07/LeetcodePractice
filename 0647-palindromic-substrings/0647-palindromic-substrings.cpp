class Solution {
public:
int t[1000][1000];
    bool solve(string &s,int i,int j){
        if(i>=j)
        return 1;
        if(t[i][j]!=-1)
        return t[i][j];
        if(s[i]==s[j])
        {
            return t[i][j]=solve(s,i+1,j-1);
        }
        return t[i][j]=0;
    }
    int countSubstrings(string s) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                  sp++;
                }
            }
        }
        return sp;
        
       
    }
};