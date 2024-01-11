class Solution {
    void traversal(TreeNode* root,int mini,int maxi,int & ans){
        if(root==NULL)
            return;
        mini = min(root->val,mini);
        maxi = max(root->val,maxi);
        ans = max(abs(maxi-mini),ans);
        if(root->left)
            traversal(root->left,mini,maxi,ans);
        if(root->right)
            traversal(root->right,mini,maxi,ans);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans =INT_MIN;
        traversal(root,INT_MAX,INT_MIN,ans);
        return ans;
    }
};