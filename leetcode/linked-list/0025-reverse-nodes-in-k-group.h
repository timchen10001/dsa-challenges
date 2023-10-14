/**
 * @see https://leetcode.com/problems/reverse-nodes-in-k-group/
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;

        ListNode *l=head, *r=head;
        for (int i=0; i<k; i++) {
            if (!r) return head; // not enough to form a group
            r = r->next;
        }

        ListNode* newHead = reverseN(l, r);
        l->next = reverseKGroup(r, k);
        return newHead;
    }
    ListNode* reverseN(ListNode* start, ListNode* end) {
        if (!start) return NULL;

        ListNode *prev=NULL, *cur=start, *next=start;
        while (cur != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};