class Solution {
public:
    vector<int> findPeaks(vector<int>& m) {
           vector<int>a;
        int n= m.size();
        for(int i=1;i<n-1;i++){
            if(m[i]>m[i-1]&&m[i]>m[i+1]){
                a.push_back(i);
            }
        }
        return a;
        
    }
};