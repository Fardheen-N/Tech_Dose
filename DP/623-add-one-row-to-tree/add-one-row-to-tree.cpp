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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        if(depth==1){
            TreeNode* nr = new TreeNode(val);
            nr->left = root;
            return nr;
        }
        q.push(root);
        depth--;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                if(depth-1==0){
                    TreeNode *l = new TreeNode(val);
                    TreeNode *r = new TreeNode(val);
                    l->left = node->left;
                    r->right = node->right;
                    node->left = l;
                    node->right = r;
                }
            }
            depth--;
            if(depth==0) break;
        }
        return root;
    }
};