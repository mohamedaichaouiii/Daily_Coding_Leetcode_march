
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b){ return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> PQ(cmp);
        for(auto l : lists)
            if(l) PQ.push(l);
        if(PQ.empty()) return nullptr;
        ListNode *head = PQ.top();
        PQ.pop();
        if(head->next) PQ.push(head->next);
        ListNode *curr = head;
        while(!PQ.empty()){
            ListNode *n = PQ.top();
            PQ.pop();
            curr->next = n;
            curr = n;
            if(n->next) PQ.push(n->next);
        }
        return head;
    }
};