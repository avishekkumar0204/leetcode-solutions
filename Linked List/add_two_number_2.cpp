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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, f = 0;
        ListNode *head = NULL, *tail = NULL;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;

            if (f == 0)
            {
                head = tail = new ListNode(sum % 10);
                f = 1;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l2 = l2->next;
        }
        if (carry)
            tail->next = new ListNode(1);
        return head;
    }
};