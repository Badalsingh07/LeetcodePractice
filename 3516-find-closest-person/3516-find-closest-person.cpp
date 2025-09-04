class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a=abs(x-z),b=abs(z-y);
        if(a<b){
            return 1;
        }
       if(a>b){
            return 2;
        }
        else
        return 0;

    }
};