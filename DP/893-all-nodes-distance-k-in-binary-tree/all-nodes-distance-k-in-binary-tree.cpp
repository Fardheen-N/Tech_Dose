/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode *> q;
        q.push(root);
        map<TreeNode*,TreeNode*> par;
        par[root]=NULL;
        TreeNode *st = NULL;
        vector<int> res;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *node = q.front();q.pop();
                if(node->left!=NULL) {par[node->left]=node;q.push(node->left);}
                if(node->right!=NULL) {par[node->right]=node;q.push(node->right);}
                if(node->val==target->val) st = node;
            }
        }
        // cout<<par.size()<<endl;
        for(auto i:par) cout<<((i.first!=NULL)?i.first->val:-1)<<" "<<((i.second!=NULL)?i.second->val:-1)<<endl;
        map<int,bool> vis;
        find(st,par,vis,res,0,k);
        return res;
    }
    void find(TreeNode *root,map<TreeNode*,TreeNode*>&par,map<int,bool>&vis,vector<int>&res,int i,int k){
        if(root==NULL) return ;

        if(vis[root->val]!=0) return ;
        vis[root->val]=1;

        if(i==k){res.push_back(root->val);return;}
        find(root->left,par,vis,res,i+1,k);
        find(root->right,par,vis,res,i+1,k);
        find(par[root],par,vis,res,i+1,k);
        
    }
};