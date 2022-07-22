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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *r1, *r2;
        for(auto i = head; i != nullptr; i = i->next){
            r2 = r2 == nullptr ? nullptr : r2->next;
            if(--k == 0){
                r1 = i;
                r2 = head;
            }
        }
        swap(r1->val, r2->val);
        return head;
    }
};