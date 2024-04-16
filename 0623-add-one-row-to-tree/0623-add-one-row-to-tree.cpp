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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) 
            return new TreeNode(val, root, nullptr);
        dfs(root, 1, val, depth);
        return root;
    }

    void dfs(TreeNode* root, int d, int val, int depth) {
        if (!root) return;
        if (d == depth - 1) {
            auto l = new TreeNode(val, root->left, nullptr);
            auto r = new TreeNode(val, nullptr, root->right);
            root->left = l;
            root->right = r;
            return;
        }
        dfs(root->left, d + 1, val, depth);
        dfs(root->right, d + 1, val, depth);
    }
};