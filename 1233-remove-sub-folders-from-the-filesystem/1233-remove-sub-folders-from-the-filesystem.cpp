class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        int n= folder.size();

        for(int i=1;i<n;i++){
            string res = ans.back();
            res.push_back('/');
            if(folder[i].compare(0, res.size(), res) != 0) {
                
                ans.push_back(folder[i]);
            }
            
        }
        return ans;
        
    }
};