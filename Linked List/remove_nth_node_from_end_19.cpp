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

// Method 1
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *A, int B)
    {
        ListNode *p = A;
        int cnt = 0;
        while (p != NULL)
        {
            cnt++;
            p = p->next;
        }
        int n = cnt - B + 1;
        n = n - 2;
        if (n == -1 || cnt < B)
        {
            A = A->next;
            return A;
        }
        p = A;
        for (int i = 1; i <= n; i++)
            p = p->next;
        p->next = p->next->next;
        return A;
    }
};

// Method 2 (one pass)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *h1 = head, *h2 = head;
        while (n--)
            h2 = h2->next;
        if (h2 == NULL)
            return head->next;
        h2 = h2->next;
        while (h2 != NULL)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        h1->next = h1->next->next;
        return head;
    }
};