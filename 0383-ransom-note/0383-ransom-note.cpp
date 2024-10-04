class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int>d(26,0);
        vector<int>v(26,0);
        for(int i=0;i<b.size();i++){
               d[b[i]-'a']++;
        }
        for(int i=0;i<a.size();i++){
            if(d[a[i]-'a']!=0)
               d[a[i]-'a']--;
            else 
            return false;
              

            
        }
       
        return true;
        
    }
};