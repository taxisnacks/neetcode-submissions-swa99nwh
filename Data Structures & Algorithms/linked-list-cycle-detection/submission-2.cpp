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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        unordered_set<int> seen;
        ListNode* current = head;
        while (current->next != nullptr){
            if (seen.count(current->val) != 0){
                return true;
            }
            else {
                seen.insert(current->val);
            }
            current = current->next;
        }
        return false;
    }
};
