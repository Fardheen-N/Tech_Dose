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
    int rob(TreeNode* root) {
        pair<int,int> p = solve(root);
        return max(p.first,p.second);
    }
    pair<int,int> solve(TreeNode *root){
        if(root==NULL) return {};
        
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        
        pair<int,int> res = {l.second+r.second+root->val,max(l.first,l.second)+max(r.first,r.second)};
        return res;
    }
};