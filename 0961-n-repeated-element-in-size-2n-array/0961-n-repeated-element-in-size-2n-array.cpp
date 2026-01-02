class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int>m;
        int a=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==a)
            {
                return i.first;
            }
        }
        return 0;
    }
};