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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        if(len == 1 || (len-n)==0){
            head = head->next;
            return head;
        }
        temp = head;
        // ListNode* curr = head;
        for(int i=1; i<(len-n); i++){
            temp = temp->next;
            // curr = curr->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};