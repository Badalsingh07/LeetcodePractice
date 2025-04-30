class Solution {
public:
    string removeDigit(string n, char d) {
        string ans="",as="";
        bool flag =false;
        for(int i=0;i<n.size();i++){
            
            if(n[i]!=d || flag==true )ans+=n[i];
            if(n[i]==d)flag=true;
        }
        for(int i=n.size()-1;i>0;i--){
            if(n[i]!=d)as+=n[i];
        }
        int a,b;
        a=stoi(ans);
        b=stoi(as);
        if(a>=b)
        return ans;  
        else return as;    
    }
};