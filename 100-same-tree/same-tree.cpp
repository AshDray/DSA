class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&q)return false;
        else if(!q&&p)return false;
        if(!p&&!q)return true;
        if(p->val==q->val){
            if(isSameTree(p->right,q->right)&&isSameTree(p->left,q->left))return true;
            else return false;
        }
        else return false;
        
    }
};