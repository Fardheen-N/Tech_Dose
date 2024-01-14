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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int some = solve(root,maxi);
        return maxi-2;
    }
    int solve(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        int lh = solve(root->left,maxi)+1;
        int rh = solve(root->right,maxi)+1;
        if(maxi<lh+rh) maxi = lh+rh;
        return max(lh,rh);
    }
};