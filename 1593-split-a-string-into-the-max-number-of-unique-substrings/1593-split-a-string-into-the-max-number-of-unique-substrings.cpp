class Solution {
    void solve(string &s,int i,unordered_set<string>&st,int &maxi,int cmaxi){
        if(i>=s.length()){
            maxi=max(maxi,cmaxi);
             return ;
        }
       
        for(int j=i;j <s.length();j++){
            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(s,j+1,st,maxi,cmaxi+1);
                st.erase(sub);
            }

        }
        
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int maxi=0;
        int cmaxi=0;
         solve(s,0,st,maxi,cmaxi);
        return maxi;

        
    }
};