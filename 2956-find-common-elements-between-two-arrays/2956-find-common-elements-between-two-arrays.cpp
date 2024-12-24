class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& m, vector<int>& m2) {
        int n=m.size();
        int n2=m2.size();
        int c1=0;
        int c2=0;

        map<int,bool>mp;
         map<int,bool>mp2;
        for(int i=0;i<n;i++){
            mp[m[i]]=true;
        }
         for(int i=0;i<n2;i++){
             mp2[m2[i]]=true;
        }
          for(int i=0;i<n;i++){
            if(mp2[m[i]]==true)
            {
              c1++;
            }
             
        }
         for(int i=0;i<n2;i++){
            if(mp[m2[i]]==true)
            {
              c2++;
            }
             
        }
         

     return {c1,c2}; 

        
    }
};