class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        stack<int> s;
        int ans=0;
        int count=1;
        s.push(colors[0]);
        for(int i=1;i<n;i++)
        {
            if(s.top()!=colors[i])
            {
                s.push(colors[i]);
                count++;
                if(count>=k)    ans++;
            }
            else    count=1;
        }
        for(int i=0;i<k-1;i++)
        {
            if(colors[i]!=s.top())
            {
                s.push(colors[i]);
                count++;
                if(count>=k)    ans++;
            }
            else return ans;
        }
        return ans;
    }
};