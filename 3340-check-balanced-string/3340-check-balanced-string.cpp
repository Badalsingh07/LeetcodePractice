class Solution {
public:
    bool isBalanced(string num) {
  int es=0;
  int os=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0)
            es += num[i] - '0';

            else 
              os += num[i] - '0';

              
        }
        if(es==os)
        return true;
        else 
        return false;

        
    }
};