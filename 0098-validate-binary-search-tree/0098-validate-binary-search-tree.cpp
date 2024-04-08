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
    bool isBST(TreeNode* curr, long l, long h) {
        if (curr == nullptr)
            return true;
        if (!(curr->val >= l && curr->val <= h))
            return false;
        if (curr->val == LONG_MAX && curr->right != nullptr)
            return false;
        if (curr->val == LONG_MIN && curr->left != nullptr)
            return false;
        return isBST(curr->left, l, curr->val - 1LL) && 
               isBST(curr->right, curr->val + 1LL, h);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};