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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) return NULL;

        ListNode *p1 =head->next, *p2 = head->next->next;

        while(p1 != NULL && p2 != NULL && p2->next != NULL)
        {
        	if(p1 == p2)
        	{
        	    p1 = head;
                while(p1 != p2)
                {
                	p1 = p1->next;
                	p2 = p2->next;
                }
                return p1;
            }
        	else
        	{
        		p1 = p1->next;
        		p2 = p2->next->next;
        	}
        }
    	
        return NULL;
    }

    ListNode *create_cycle_list(int *A, int len, int connect)
    {
    	ListNode *root = new ListNode(A[0]);

    	ListNode *tail = root, *joint = root;
    	for(int i = 1; i < len; ++i )
    	{
    		ListNode *newNode = new ListNode(A[i]);
    		tail->next = newNode;
    		tail = newNode;

    		if(i == connect)
    		{
    			joint = tail;
    			printf("joint %d \n", joint->val);
    		}
    	}

    	tail->next = joint;

    	return root;
    }

    void print_cycle_list(ListNode *head, int len)
    {
    	ListNode *p = head;
    	for(int i = 0; i < len; ++i)
    	{
    		printf("%d ", p->val);
    		p = p->next;
    	}

    	printf("connect point %d\n", p->val);

    	printf("\n");
    }
};

int main()
{
	Solution sln;

	int A[] = {1,2,3,4,5};
	ListNode *list = sln.create_cycle_list(A, sizeof(A)/sizeof(A[0]), 2);
	sln.print_cycle_list(list, sizeof(A)/sizeof(A[0]));

	ListNode *connect = sln.detectCycle(list);
	if(connect == NULL)
		printf("NULL\n");
	else
		printf("connect at %d\n", connect->val);
	return 0;
}