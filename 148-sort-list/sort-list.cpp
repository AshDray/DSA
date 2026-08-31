class Solution {
public:
    void split(ListNode* src, ListNode*& left, ListNode*& right) {
        ListNode* slow = src;
        ListNode* fast = src->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        left = src;
        right = slow->next;
        slow->next = nullptr;
    }

    ListNode* sortedmerge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;
        ListNode* result = nullptr;
        if (left->val <= right->val) {
            result = left;
            result->next = sortedmerge(left->next, right);
        } else {
            result = right;
            result->next = sortedmerge(left, right->next);
        }
        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* left = nullptr;
        ListNode* right = nullptr;
        
        split(head, left, right);
        
        left = sortList(left);
        right = sortList(right);
        
        return sortedmerge(left, right);
    }
};