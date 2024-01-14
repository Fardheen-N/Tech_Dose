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
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inOrder(root,in);
        for(int i=1;i<in.size();i++){
            if(in[i-1]>=in[i]) return 0;
        }
        return 1;
    }
    void inOrder(TreeNode *root,vector<int>&in){
        if(root==NULL) return ;
        inOrder(root->left,in);
        in.push_back(root->val);
        inOrder(root->right,in);
    }
};