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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        map<TreeNode*,TreeNode*> par;
        q.push(root);
        while(!q.empty()){
            TreeNode* a = NULL,*b = NULL;
            int size = q.size();
            while(size--){
                TreeNode *node = q.front();q.pop();
                if(node->left!=NULL) {par[node->left]=node;q.push(node->left);}
                if(node->right!=NULL) {par[node->right]=node;q.push(node->right);}
                if(node->val==x) a=node;
                if(node->val==y) b=node;
            }
            if(a&&b&&par[a]!=par[b]) return 1;
        }
        return 0;
    }
};