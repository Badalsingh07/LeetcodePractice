class Solution {
public:
    int smallestNumber(int n) {
        for(int i=0;i<n;i++){
            if(pow(2,i)-1>=n)
              return pow(2,i)-1;
        }
        return 1;
    }
};