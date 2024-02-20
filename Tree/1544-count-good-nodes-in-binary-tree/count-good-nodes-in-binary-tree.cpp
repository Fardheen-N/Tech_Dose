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
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
    int solve(TreeNode *root,int maxi){
        if(root == NULL) return 0;
        int res = 0;
        if(root->val>=maxi) res++; 
        if(maxi<root->val) maxi=root->val;
        int lh = solve(root->left,maxi);
        int rh = solve(root->right,maxi);
        return res+lh+rh;
    }
};