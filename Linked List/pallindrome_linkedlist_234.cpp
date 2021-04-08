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
class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *nxt = curr->next;
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (nxt)
                nxt = nxt->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *p1)
    {
        ListNode *s = p1, *f = p1;
        while (f != NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }
        ListNode *p2 = rev(s);
        while (p2 != NULL)
        {
            if (p1->val != p2->val)
                return 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        return 1;
    }
};