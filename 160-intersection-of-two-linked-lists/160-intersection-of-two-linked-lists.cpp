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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b = headB;
        int c1=0, c2=0;
        for(ListNode *curr = headA; curr != NULL; curr=curr->next)
            c1++;
        for(ListNode *curr = headB; curr != NULL; curr=curr->next)
            c2++;
        while(c1>c2){
            c1--;
            a = a->next;
        }
        while(c2>c1){
            c2--;
            b=b->next;
        }
        
        while(a!=b){
            a=a->next;
            b=b->next;
        }
        return a;
    }
};