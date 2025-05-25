class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        
        for(string &w : words){
            string rs=w;
            swap(w[0],w[1]);
            if(mp[rs] >0){
                mp[rs]--;
                ans+=4;
            }
            else
            {
                mp[w]++;
            }  
        }
        //check equal no
        for(auto &it:mp){
            string s= it.first;
            int t=it.second;
            if(s[0]==s[1] && t>0){
                ans+=2;
                break;
            }
        }

    return ans;
        
    }
};