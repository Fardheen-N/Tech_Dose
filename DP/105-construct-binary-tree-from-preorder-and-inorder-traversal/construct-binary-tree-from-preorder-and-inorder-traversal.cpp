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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder);
    }
    TreeNode *solve(vector<int> pre,vector<int> in){
        if(pre.size()==1) return new TreeNode(pre[0]);
        TreeNode *root = new TreeNode(pre[0]);
        
        int i = 0;
        for(int j=0;j<in.size();j++) if(in[j]==pre[0]) i = j;
        if(i!=0)
        root->left = solve({pre.begin()+1,pre.begin()+i+1},{in.begin(),in.begin()+i});
        if(i!=in.size()-1)
        root->right = solve({pre.begin()+i+1,pre.end()},{in.begin()+i+1,in.end()});
        return root;
    }
};