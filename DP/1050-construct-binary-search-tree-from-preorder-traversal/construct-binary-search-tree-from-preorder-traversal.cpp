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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;
        for(auto i:preorder){
            root=insert(root,i);
        }
        return root;
    }
    TreeNode* insert(TreeNode *root,int val){
        if(root==NULL) return new TreeNode(val);
        if(val<root->val) root->left=insert(root->left,val);
        if(val>root->val) root->right=insert(root->right,val);
        return root;
    }
};