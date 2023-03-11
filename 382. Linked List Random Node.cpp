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
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* curr = head;
        int i = 1;
        int res = 0;
        while (curr != nullptr) {
            if (rand() % i == 0) {
                // take this value
                res = curr->val;
            }
            i++;
            curr = curr->next;
        }
        return res;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */













