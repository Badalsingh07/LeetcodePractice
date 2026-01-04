class Solution {
public:
    int sumFourDivisors(vector<int>& n) {
        int t = 0;

        for(int i = 0; i < n.size(); i++) {
            int sum = 0;
            int c = 0;

            for(int j = 1; j * j <= n[i]; j++) {
                if(n[i] % j == 0) {
                    sum += j;
                    c++;

                    if(j != n[i] / j) {
                        sum += n[i] / j;
                        c++;
                    }
                }

                if(c > 4) break; 
            }

            if(c == 4) t += sum;
        }

        return t;
    }
};
