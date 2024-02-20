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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> set;
        queue<pair<TreeNode*,int>> q;
        set[0].push_back(root->val);
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            multiset<pair<int,int>> pq;
            while(size--){
                pair<TreeNode*,int>node = q.front();q.pop();
                if(node.first->left!=NULL) {
                    q.push({node.first->left,node.second-1});
                    //set[node.second-1].push_back(node.first->left->val);
                    pq.insert({node.first->left->val,node.second-1});
                }
                if(node.first->right!=NULL) {
                    q.push({node.first->right,node.second+1});
                    //set[node.second+1].push_back(node.first->right->val);
                    pq.insert({node.first->right->val,node.second+1});
                }
            }
            for(auto i:pq){
                set[i.second].push_back(i.first);
            }
        }
        
        vector<vector<int>> res;
        for(auto i:set){
            int pi = i.first;
            res.push_back(i.second);
        }
        return res;
    }
    // void inOrder(){
    //     if(!root) return ;
        
    //     inOrder()
    // }
};