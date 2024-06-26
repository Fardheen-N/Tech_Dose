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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inOrder(root,in);
        TreeNode* bTree=balance(0,in.size()-1,in);
        return bTree;
    }
    void inOrder(TreeNode *root,vector<int> &in){
        if(root==NULL) return ;
        inOrder(root->left,in);
        in.push_back(root->val);
        inOrder(root->right,in);
    }
    TreeNode *balance(int l,int r,vector<int> &in){
        if(l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = balance(l,mid-1,in);
        root->right = balance(mid+1,r,in);
        return root;
    }
};