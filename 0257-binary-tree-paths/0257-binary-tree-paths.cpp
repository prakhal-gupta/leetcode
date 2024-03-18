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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        else if(!root->left && !root->right)
            return {"1"};
        else{
            vector<string> paths;
            traverse(root, "", paths);
            return paths;
        }
    }
    
    void traverse(TreeNode* node, string path, vector<string>& paths) {
        if (!node)
            return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }
        path += "->";
        traverse(node->left, path, paths);
        traverse(node->right, path, paths);
    }
};