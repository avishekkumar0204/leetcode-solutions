ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode *ans;
    if (l1->val < l2->val)
    {
        l1->next = merge(l1->next, l2);
        ans = l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        ans = l2;
    }
    return ans;
}
ListNode *mergeSort(ListNode *head)
{
    if (head->next == NULL)
        return head;
    ListNode *p = head, *prev = NULL, *s = head, *f = head;
    while (f != NULL && f->next != NULL)
    {
        prev = s;
        s = s->next;
        f = f->next->next;
    }
    if (prev)
        prev->next = NULL;
    p = mergeSort(p);
    s = mergeSort(s);
    head = merge(p, s);
    return head;
}