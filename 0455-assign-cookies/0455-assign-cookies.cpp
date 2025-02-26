class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int n1=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;int r=0;
        while(l<n1 && r<n){
            if(g[r]<=s[l]){
                r=r+1;
            }
            l=l+1;

        }
        return r;
        
    }
};