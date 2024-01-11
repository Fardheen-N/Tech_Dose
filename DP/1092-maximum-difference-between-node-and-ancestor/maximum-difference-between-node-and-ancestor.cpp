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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root,root->val,0,ans);
        return ans;
    }
    void solve(TreeNode*root,int mi,int ma,int &ans){
        if(root==NULL) return ;
        if(mi>root->val) mi=root->val;
        if(ma<root->val) ma=root->val;
        ans = max({ans,abs(mi-root->val),abs(ma-root->val)});
        solve(root->left,mi,ma,ans);
        solve(root->right,mi,ma,ans);
    }
};