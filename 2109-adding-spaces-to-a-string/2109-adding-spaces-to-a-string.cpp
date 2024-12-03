class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int j = 0; 
        int n = s.size();
        int m = spaces.size();

        for (int i = 0; i < n; i++) {
           
            if (j < m && i == spaces[j]) {
                result += ' ';
                j++;
            }
            result += s[i];
        }

        return result;
    }
};
