/**
 * @see https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        for (int i=1; i<left; i++) {
            prev = prev->next;
        }

        ListNode* cur = prev->next;
        for (int i=left; i<right; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};