/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode* tmp = headB;
            while(tmp){
                if(tmp==headA)return headA;
                tmp=tmp->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
};