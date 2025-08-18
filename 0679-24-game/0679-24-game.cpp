class Solution {
public:
     double epsilon= 0.1;
     bool solve(vector<double>&card){
        if(card.size()==1){
            if(abs(card[0]-24)<=epsilon)
            return true;
        }
       

        for(int i=0;i<card.size();i++){
            for(int j=0;j<card.size();j++){
                if(i==j)continue;
                      
                    vector<double>rem;
                    for(int k=0;k<card.size();k++){
                        if(k!=i && k!=j)rem.push_back(card[k]);
                    }
                     double a=card[i],b=card[j];
                      vector<double>temp= {a+b,a*b,a-b,b-a};
                     if(abs(b)>0.0)temp.push_back(a/b);
                     if(abs(a)>0.0)temp.push_back(b/a);
                    
                    for(double l:temp){
                        rem.push_back(l);//do
                       if(solve(rem)==true)return true ;//explore
                        rem.pop_back();//undo

                    }

            }
        }
          return false;
     }
    bool judgePoint24(vector<int>& cards) {
        
        vector<double> num;
        for(int i=0;i<cards.size();i++){
            num.push_back(1.0*cards[i]);
        }
        return solve(num);
    }
};