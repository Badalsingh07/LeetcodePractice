class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);
        string s2=s;
        char mx1,mx2;
      
        int n= s.size();
        sort(s2.begin(),s2.end(),greater<char>());
        for(int i=0;i<n;i++){
            if(s[i]!=s2[i]){
                 mx1=s2[i];
                 mx2=s[i];
                 break;
            }
        }
        int start=0;
        int end=n-1;
         for(int i=0;i<n;i++){
            if(s[start]==mx2 && s[end]==mx1){
               swap(s[start],s[end]);
               break;
            }
            if(s[start]!=mx2) start++;
           if(s[end]!=mx1) end--;

         }

          
        
        return stoi(s);

        
    }
};