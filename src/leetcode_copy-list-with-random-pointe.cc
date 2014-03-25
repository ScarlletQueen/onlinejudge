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
    map<RandomListNode*, RandomListNode*> nodemap_;

    RandomListNode *getNode(RandomListNode *node)
    {
        if(node == NULL) return NULL;

        RandomListNode *ret = NULL;

        if(nodemap_.count(node) == 0)
        {
            ret = new RandomListNode(node->label);
            nodemap_[node] = ret;
        }
        else
        {
            ret = nodemap_[node];
        }

        return ret;
    }
    
    RandomListNode *copyRandomList(RandomListNode *head) {

        RandomListNode newHead(-1), *tail = &newHead; 

        RandomListNode *p = head;
        while(p != NULL)
        {
            RandomListNode *node = getNode(p);

            if(p->random != NULL)
            {
                node->random = getNode(p->random);
            }

            tail->next = p;
            tail = tail->next;
            p = p->next;
        }

        return newHead.next;
    }

    RandomListNode *copyRandomList_small(RandomListNode *head) {
        
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
    sln.print_list(newList);


}