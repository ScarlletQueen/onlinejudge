#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        ListNode tmp(-1);
        tmp.next = head;

        ListNode *p = &tmp, *q = &tmp;

        for(int i = 0; i < n; ++i)
        	q = q->next;

        while(q->next != NULL)
        {
        	p = p->next;
        	q = q->next;
        }

        p->next = p->next->next;

        return tmp.next;
    }
};