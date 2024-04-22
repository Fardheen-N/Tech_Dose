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
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre;
        save(pre,root);
        TreeNode *t = root;
        root = flat(pre,0);
    }
    TreeNode* flat(vector<TreeNode*>&pre,int i){
        if(i==pre.size()) return NULL;
        TreeNode *root = pre[i];
        root->left = NULL;
        root->right=flat(pre,i+1);
        return root;
    }
    void save(vector<TreeNode*> &pre,TreeNode *root){
        if(root==NULL) return ;
        pre.push_back(root);
        save(pre,root->left);
        save(pre,root->right);
    }
};