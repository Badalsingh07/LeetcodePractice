class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
        vector<int>ans;
        int n=w.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<w[i].size();j++){
                if(w[i][j]==x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
        
    }
};