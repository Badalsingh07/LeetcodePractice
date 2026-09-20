class Solution {
public:
    int reverseDegree(string s) {
        int n= s.length();
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=(26-(s[i-1]-'a'))*i;
            
        }
        return sum;
    }
};