class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>v(n+1);
        v[0]=0;
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=gain[i];
            v[i+1]=sum; 
        }
        int ans=*max_element(v.begin(),v.end());

        return ans;
        
    }
};