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
    ListNode *rotateRight(ListNode *head, int k) {
		
		if(head == NULL) return NULL;
		int len = getLength(head);
		k %= len;

		ListNode tmp(-1);
		tmp.next = head;

		ListNode *p = &tmp, *q = &tmp;

		for(int i = 0; i < k; ++i)
			q = q->next;

		while(q->next != NULL)
		{
			p = p->next;
			q = q->next;
		}

		q->next = head;
		tmp.next = p->next;
		p->next = NULL;

		return tmp.next;
    }

    int getLength(ListNode *head)
    {
    	int len = 0;

    	ListNode *p = head;
    	while( p != NULL)
    	{
    		++len;
    		p = p->next;
    	}

    	return len;
    }

};