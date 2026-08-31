/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* a=head;
        if(!a ||!a->next)return head;
        int ct=0;
        while(a->next){
           ct++;
           a=a->next;
        } 
        a->next=head;
        int p=k%(ct+1);
        ListNode*b=head;
        for(int i=0;i<ct-p;i++){
            b=b->next;

        }
        ListNode* ans=b->next;
        b->next=nullptr;
        return ans;
    }
};