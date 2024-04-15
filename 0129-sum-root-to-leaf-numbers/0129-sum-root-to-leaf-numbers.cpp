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
    void sumNumbersHelper(TreeNode* node, int currentSum, int& totalSum) {
        if(node == NULL) return;
        currentSum = currentSum * 10 + node->val;
        if(node->left == NULL && node->right == NULL) {
            totalSum += currentSum;
            return;
        }
        sumNumbersHelper(node->left, currentSum, totalSum);
        sumNumbersHelper(node->right, currentSum, totalSum);
    }
    
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        sumNumbersHelper(root, 0, totalSum);
        return totalSum;
    }
};