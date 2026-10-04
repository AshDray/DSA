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
int dfs(TreeNode* t,int mini, int maxi){
    if(!t){
        return maxi-mini;
    }
    mini=min(mini,t->val);
    maxi=max(maxi,t->val);
    int ld=dfs(t->left,mini,maxi);
    int rd=dfs(t->right,mini,maxi);
    return max(ld,rd);
}
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
        return dfs(root,root->val,root->val);
    }
};