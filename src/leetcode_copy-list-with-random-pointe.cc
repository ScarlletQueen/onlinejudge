#include <stdio.h>
#include <map>
#include <vector>
using namespace std;


/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(head == NULL) return NULL;

        RandomListNode newHead(-1);
        RandomListNode *tail = &newHead;

        RandomListNode *p = head;
        while(p != NULL)
        {
        	RandomListNode *newNode = new RandomListNode(p->label);
        	tail->next = newNode;

        	tail = tail->next;
        	p = p->next;
        }

        print_list(newHead.next);

        p = head;
        RandomListNode *q = newHead.next;

        while(p != NULL)
        {
        	printf("p = %d\n", p->label);

        	if(p->random != NULL)
        	{
    			RandomListNode *tmp = head;
    			RandomListNode *tmp2 = newHead.next;

    			while(tmp != NULL && tmp != p->random)
    			{
        			tmp = tmp->next;
        			tmp2 = tmp2->next;        				
    			}

        		q->random = tmp2;
        	}

        	p = p->next;
        	q = q->next;
        }

        return newHead.next;
    }

    void print_list(RandomListNode *list)
    {
    	RandomListNode *p = list;
    	while(p != NULL)
    	{
    		printf("%d ", p->label);
    		p = p->next;
    	}
    	printf("\n");

    	p = list;
    	while(p != NULL)
    	{
    		if(p->random == NULL)
    			printf("# ");
    		else
    			printf("%d ", p->random->label);
    		
    		p = p->next;
    	}
    	printf("\n");
    }
};

int main()
{
	RandomListNode *list;
	RandomListNode n1 = RandomListNode(-1);
	RandomListNode n2 = RandomListNode(8);
	RandomListNode n3 = RandomListNode(7);
	RandomListNode n4 = RandomListNode(-3);
	RandomListNode n5 = RandomListNode(4);
	n1.next = &n2;
	n1.random = &n5; 
	n2.next = &n3;
	n2.random = &n4;
	n3.next = &n4;
	n4.next = &n5;
	n5.random = &n1;

	list = &n1;

	Solution sln;
	sln.print_list(list);
	RandomListNode *newList = sln.copyRandomList(list);


}