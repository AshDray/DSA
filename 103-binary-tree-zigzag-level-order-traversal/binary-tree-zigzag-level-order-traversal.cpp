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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
vector<vector<int>>result;
if(!root)return result;
        q.push(root);
        bool p=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
            TreeNode* f=q.front();
            q.pop();
            int index=p?i:size-1-i;
            level[index]=f->val;
            if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            p=!p;
            result.push_back(level);
        }
        return result;
    }
};