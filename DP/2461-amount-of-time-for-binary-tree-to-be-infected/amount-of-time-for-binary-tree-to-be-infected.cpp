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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        int cnt =0;
        map<TreeNode*,TreeNode*> par;
        map<TreeNode*,int> vis;
        TreeNode *st=NULL;
        q.push(root);
        par[root]=NULL;
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            if(node->left!=NULL){ q.push(node->left);par[node->left]=node;}
            if(node->right!=NULL){ q.push(node->right);par[node->right]=node;}
            if(node->val==start) st=node;
        }
        q.push(st);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();q.pop();
                vis[node]=1;
                if(node->left!=NULL&&vis[node->left]==0) q.push(node->left); 
                if(node->right!=NULL&&vis[node->right]==0) q.push(node->right); 
                if(par[node]!=NULL&&vis[par[node]]==0) q.push(par[node]);
            }
            cnt++;
        }
        return cnt-1;
    }
};