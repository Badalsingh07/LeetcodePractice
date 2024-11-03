class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.size())
        return false;
        int n= s.size();
        char k=goal[0];
        string a="";string a1="";
        for(int i=0;i<n;i++){
            if(s[i]!=k)
             a+=s[i];
             else 
              break;
        }
        int b=a.size();
        for(int i=b;i<n;i++){
            a1+=s[i];
        }
        string ans =a1+a;
        if(ans == goal)
        return true;
        else return false;
        
    }
};