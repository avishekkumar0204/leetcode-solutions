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
    ListNode *swapNodes(ListNode *curr, ListNode *currNext)
    {
        curr->next = currNext->next;
        currNext->next = curr;
        return currNext;
    }

    ListNode *swapPairs(ListNode *head)
    {
        ListNode *temp = new ListNode(-23);
        ListNode *prev = temp;
        temp->next = head;
        while (prev->next != NULL && prev->next->next != NULL)
        {
            prev->next = swapNodes(prev->next, prev->next->next);
            prev = prev->next->next;
        }
        return temp->next;
    }
};