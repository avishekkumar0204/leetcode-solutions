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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *p=head,*prev=NULL,*p1=p->next;
        while(p!=NULL)
        {
            p->next=prev;
            prev=p;
            p=p1;
            if(p1) p1=p1->next;
        }
        return prev;
        
    }
};