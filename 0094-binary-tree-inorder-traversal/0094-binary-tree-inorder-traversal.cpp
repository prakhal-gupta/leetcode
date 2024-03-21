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
    // void inorder(TreeNode*&root,vector<int>&ans){
    //     if(root){
    //         inorder(root->left,ans);
    //         ans.push_back(root->val);
    //         inorder(root->right,ans);
    //     }
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(!root)
    //         return {};
    //     vector<int> ans;
    //     inorder(root,ans);
    //     return ans;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
                return {};
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            if (!curr.second) {
                if(curr.first->right)
                    st.push({curr.first->right, false});
                st.push({curr.first, true});
                if(curr.first->left)
                    st.push({curr.first->left, false});
            } else {
                ans.push_back(curr.first->val);
            }
        }
        return ans;
    }
};