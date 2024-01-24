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

    void preorder(TreeNode* root, unordered_map<int, int> mp, int& ans) {
        mp[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            int cnt = 0;
            for (auto x : mp) {
                if (x.second % 2 != 0)
                    cnt++;
                if (cnt > 1)
                    return;
            }
            ans++;
            return;
        }
        if (root->left)
            preorder(root->left, mp, ans);
        if (root->right)
            preorder(root->right, mp, ans);
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (root == NULL)
            return 0;
        int ans = 0;
        preorder(root, {}, ans);
        return ans;
    }
};