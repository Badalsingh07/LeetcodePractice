class Solution {
public:
    int numWaterBottles(int nb, int nexc) {
        int cnt = nb,empty = nb;
        while(empty>0){
            if(empty>=nexc){
                cnt++;
                empty-=nexc;
                empty++;
            }
            else break;
        }
        return cnt;
    }
};