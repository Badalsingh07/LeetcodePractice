/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long MOD = 1e9 + 7;
    long long maxProd = 0;


    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long dfs(TreeNode* root, long long total) {
        if (!root) return 0;

        long long left = dfs(root->left, total);
        long long right = dfs(root->right, total);

        long long subTreeSum = left + right + root->val;

        maxProd = max(maxProd, subTreeSum * (total - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        long long total = totalSum(root);
        dfs(root, total);
        return maxProd % MOD;
    }
};
