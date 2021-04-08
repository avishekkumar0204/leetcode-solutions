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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        while(p!=NULL)
        {
            ListNode *p1=p->next;
            while(p1!=NULL && p1->val==p->val)
                p1=p1->next;
            p->next=p1;
            p=p1;
        }
        return head;
    }
};