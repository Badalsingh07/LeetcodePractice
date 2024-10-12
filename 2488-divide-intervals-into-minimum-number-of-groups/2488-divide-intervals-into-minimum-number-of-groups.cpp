class Solution {
public: typedef pair<int,int>p;
    int minGroups(vector<vector<int>>& i) {
        priority_queue<int,vector<int>,greater<int>>pq;

     sort(i.begin(), i.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    for(int k=0;k<i.size();k++){
        int second=i[k][1];
        int first=i[k][0];
        if(!pq.empty() && first>pq.top()){
            pq.pop();
            pq.push(second);
        }
        else
        {
            pq.push(second);
        }
    }
    return pq.size();
    }
};