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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            int prev = -1;
            while(size--){
                TreeNode *node  = q.front();
                q.pop();
                if(lvl%2==0){
                    if(prev!=-1 && prev>=node->val || node->val%2==0) return false;
                }else{
                    if(prev!=-1 && prev<=node->val || node->val%2==1) return false;
                }
                prev = node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            lvl++;
        }
        return true;
    }
};