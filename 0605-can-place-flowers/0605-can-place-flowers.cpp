class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int k=f.size();
        for(int i=0;i<k;i++){
            if(f[i]==0 && f[i-1]!=1){
                if(f[i+1]!=1){
                 f[i]=1;
                n--;
                }
                
            }
           

        }
        if(n!=0)
        return false;
        else 
        return true;
        
    }
};