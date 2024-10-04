class Solution {
public:
    long long dividePlayers(vector<int >& skill) {
        long long int n= skill.size();

        
        long long int sum=0;
        for(long long int i=0;i<n;i++){
            sum+=skill[i];
        }
         sort(skill.begin(),skill.end());
         long long int total =sum/(n/2);

        if(sum % (n/2)==0 && ((skill[0]+skill[n-1])==total)){
           
            long long int start=0;
            long long int end=n-1;
            long long int ans=0;
            for(long long int i=0;i<n/2;i++){
                ans+=(skill[start]*skill[end]);
                start++;
                end--;
                
            }
            return ans;


        }
        else 
        return -1;
        
        
        
    }
};