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
    void reorderList(ListNode* head) {
        int len=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }

        temp = head;
        int mid = len / 2;
        for(int i=0; i<mid; i++)
            temp = temp->next;

        ListNode* second = temp;

        ListNode* prevH = NULL;
        ListNode* prevS = NULL;

        while(second){
            ListNode* curr = second->next;
            second->next = prevH;
            prevH = second;
            second = curr;
        }

        second = prevH;
        prevH = NULL;
        temp = head;
        int count = 1;
        prevS = second;
        while(count < len){
            if(count%2 != 0){
                prevH = temp->next;
                temp->next = prevS;
            }
            else{
                prevS = temp->next;
                temp->next = prevH;

            }
            temp = temp->next;
            count++;
        }
    }
};