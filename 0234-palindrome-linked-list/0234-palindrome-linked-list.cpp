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
private:
    // Step 1: Find middle node (slow-fast pointer)
    ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) { // condition change ki
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    // Step 2: Reverse a linked list (recursive)
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // Step 3: Get second half reversed
        ListNode* middle  = findMiddle(head);
        ListNode* newHead = reverseList(middle->next);

        // Step 4: Compare both halves
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;
        while (temp2 != NULL) {
            if (temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};