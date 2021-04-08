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
    ListNode *rev(ListNode *A)
    {
        ListNode *prev=NULL,*p=A,*p1=p->next;
        while(p!=NULL)
        {
            p->next=prev;
            prev=p;
            p=p1;
            if(p1) 
                p1=p1->next;
        }
        return prev;
    }
    void reorderList(ListNode* h1) {
        ListNode *s=h1,*f=h1;
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        ListNode *h2=rev(s);
        ListNode *p=h1,*p1=p->next;
        ListNode *q=h2,*q1=q->next;

        while(q1!=NULL)
        {
            p->next=q;
            q->next=p1;
            p=p1;
            q=q1;
            p1=p->next;
            q1=q->next;
        }
        
    }
};