class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<int> v;

    
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                while (!st.empty() && st.top() > 0 && st.top() < abs(a[i])) {
                    st.pop();  // Destroy smaller positive asteroids
                }
                if (!st.empty() && st.top() > 0 && st.top() == abs(a[i])) {
                    st.pop();  // Both asteroids explode
                } else if (st.empty() || st.top() < 0) {
                    st.push(a[i]);  // No collision, push the negative asteroid
                }
            } else {
                st.push(a[i]);  // Push positive asteroids
            }
        }

        // Collect the remaining asteroids from the stack
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }

        // Reverse the result to get the correct order
        reverse(v.begin(), v.end());

        return v;
    }
};
