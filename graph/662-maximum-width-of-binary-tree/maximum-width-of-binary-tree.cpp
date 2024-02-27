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
typedef long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans=0;
        queue<pair<TreeNode *,ll>> q;
        q.push({root,0});
        while(!q.empty()){
           int size = q.size();
           int lvl = q.front().second;
           ll l = 0;
           ll r =0;
           for(int i = 0;i<size;i++){
                TreeNode *node = q.front().first;
                ll ind = q.front().second-lvl;
                q.pop();
                if(i==0) l = ind;
                r = ind;
                if(node->left!=NULL) q.push({node->left,(long long)ind*2+1});
                if(node->right!=NULL) q.push({node->right,(long long)ind*2+2});
           } 
           ans = max(ans,r-l+1);
        }
        return ans;
    }
};