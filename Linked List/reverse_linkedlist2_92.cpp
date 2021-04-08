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
    void rev(ListNode *start,ListNode *last,ListNode *lastNext)
    {
        ListNode *prev=NULL,*startCpy=start,*p=startCpy->next;
        while(startCpy!=lastNext)
        {
            startCpy->next=prev;
            prev=startCpy;
            startCpy=p;
            if(p!=lastNext)
                p=p->next;
        }
        return;

    }
    ListNode* reverseBetween(ListNode* A, int B, int C) {
        ListNode *ptr=A,*startPrev=NULL,*last=NULL;
        int i=1;
        // Finding the location from where to where we have to reverse.
        while(true)
        {
            //Suppose i have to reverse from 4th to 6th node then after reversing i have to link my 3rd node with head
            //of new reversed node i.e why i am taking B-1 and storing that node address to startPrev(store address of 3rd
            // node.
            if(i==B-1)
                startPrev=ptr;
            //
            if(i==C)
            {
                last=ptr;
                break;
            }
            i++;
            ptr=ptr->next;
        }
        ListNode *start,*lastNext;
        if(startPrev==NULL)
            start=A;
        else start=startPrev->next;
        lastNext=last->next;
        //Reversing from start(4th) to last(6th).
        rev(start,last,lastNext);
        if(startPrev!=NULL)
            startPrev->next=last;
        else A=last;
        start->next=lastNext;
        return A;
        
    }
};