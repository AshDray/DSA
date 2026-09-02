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
    int diameterOfBinaryTree(TreeNode* root) {
        int di=0;
        heights(root,di);
        return di;
    }

    int heights(TreeNode* root,int &di){
        if(!root)return 0;
        int lh=heights(root->left,di);
        int rt=heights(root->right,di);
        di=max(di,lh+rt);
        return 1+max(lh,rt);
    }
};