class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Use sets to store unique elements
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> res1, res2;

        // Find elements in set1 that are not in set2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                res1.push_back(num);
            }
        }

        // Find elements in set2 that are not in set1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                res2.push_back(num);
            }
        }

        // Store the results in the answer vector
        return {res1, res2};
    }
};
