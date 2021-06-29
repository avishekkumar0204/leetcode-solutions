class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-101);
        dummy->next = head;
        ListNode *curr = head, *prev = dummy;
        head = dummy;
        while (curr!=NULL && curr->next != NULL)
        {
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
                prev->next = curr->next;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};