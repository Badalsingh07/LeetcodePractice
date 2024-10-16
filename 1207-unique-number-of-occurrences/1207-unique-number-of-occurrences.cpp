class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>v;
        
       unordered_map<int,int>m;
       for(auto i: arr){
          m[i]++;
       }
        for(auto i: m){
          v.push_back(i.second);
       }
       sort(v.begin(),v.end());
       for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1])
        return false;
       }
       return true;
    }
};