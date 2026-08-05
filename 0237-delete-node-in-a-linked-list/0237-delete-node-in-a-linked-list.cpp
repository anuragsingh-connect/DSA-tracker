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
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value from the next node into the current node
        node->val = node->next->val;
        
        // Step 2: Save the next node so we can safely delete it from memory
        ListNode* temp = node->next;
        
        // Step 3: Bypass the next node
        node->next = node->next->next;
        
        // Step 4: Free the memory of the bypassed node
        delete temp; 
    }
};