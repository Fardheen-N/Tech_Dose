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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int some = solve(root,maxi);
        return maxi;
    }
    int solve(TreeNode *root,int &maxi){
        if(root==NULL) return 0;
        
        int l = solve(root->left,maxi)+(root->val);
        int r = solve(root->right,maxi)+(root->val);
        // if(maxi<l+r+(root->val)) maxi = l+r+(root->val);  
        maxi = max({maxi,l+r-(root->val),root->val,l,r});
        return max({l,r,root->val}); 
    }

};