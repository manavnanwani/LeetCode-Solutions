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
    struct compare{
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };
    
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
                q.push(lists[i]);
        }
        
        while(!q.empty()){
            auto t = q.top();
            q.pop();
            temp->next = t;
            temp = temp->next;
            if(t->next)
                q.push(t->next);
        }
        
        return head->next;
    }
};