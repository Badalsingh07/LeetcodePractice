class Solution {
public:
    string compressedString(string s) {
        int n = s.size();
        string ans = "";
        map<char, int> m;
        
 
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        
        for (auto i : m) {
            if (i.second > 9) {
                int pre = i.second - 9;
                ans += "9" + string(1, i.first) + to_string(pre) + string(1, i.first);
            } else {
                ans += to_string(i.second) + i.first;
            }
        }
        
        return ans;
    }
};
