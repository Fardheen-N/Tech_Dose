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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        if(solve(root,res)==-1) return ++res;
        return res;
    }
    int solve(TreeNode* root,int &res){
        if(root==NULL) return 1;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        if(l==-1||r==-1){
            res++;
            return 0;
        }
        if(l==0 || r==0){
            return 1;
        }
        return -1;
    }
};