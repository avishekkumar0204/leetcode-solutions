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
    ListNode* removeNthFromEnd(ListNode* A, int B) {
        ListNode *p=A;
        int cnt=0;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        int n=cnt-B+1;
        n=n-2;
        if(n==-1 || cnt<B)
        {
            A=A->next;
            return A;
        }
        p=A;
        for(int i=1;i<=n;i++)
            p=p->next;
        p->next=p->next->next;
        return A;
        
    }
};