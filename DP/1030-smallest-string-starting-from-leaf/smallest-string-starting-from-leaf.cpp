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
    string smallestFromLeaf(TreeNode* root) {
        string res = "zzzzzzzzzzzzzzzzzzzz";
        queue<pair<TreeNode*,string>> q;
        q.push({root,""});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *node = q.front().first;
                char ch = node->val+97;
                string cur = ch+q.front().second;
                if(node->left==NULL && node->right==NULL) if(cur<res) res = cur;
                q.pop();
                if(node->left!=NULL) q.push({node->left,cur});
                if(node->right!=NULL) q.push({node->right,cur});
            }
        }
        return res;
    }
};