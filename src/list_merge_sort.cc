// sort a single list

#include <stdio.h>


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL){}
};

ListNode* create_list();
ListNode* sort_list(ListNode *list);
ListNode* list_middle(ListNode *list);
void print_list(ListNode *list);

int main()
{
	ListNode *list = create_list(); 
	print_list(list);	
	
	list = sort_list(list);
	
	print_list(list);

	return 0;
}

ListNode* sort_list(ListNode *list)
{
	if(list == NULL) return NULL;
	if(list->next == NULL) return list;

	ListNode *middle = list_middle(list);

	ListNode *leftHead = list;
	ListNode *rightHead = middle->next;
	middle->next = NULL;

	leftHead = sort_list(leftHead);
	rightHead = sort_list(rightHead);

	ListNode *newList = NULL, *newTail = NULL;
	ListNode *leftNext = NULL, *rightNext = NULL;
	while(leftHead != NULL && rightHead != NULL)
	{
		leftNext = leftHead->next;
		rightNext = rightHead->next;

		ListNode *cur = NULL;
		if(leftHead->val < rightHead->val)
		{
			cur = leftHead;
			leftHead = leftNext;
		}
		else
		{
			cur = rightHead;
			rightHead = rightNext;
		}
		cur->next = NULL;

		if(newList == NULL)
		{
			newList = newTail = cur;
		}
		else
		{
			newTail->next = cur;
			newTail = cur;
		}
	}

	if(leftHead != NULL)
		newTail->next = leftHead;
	else
		newTail->next = rightHead;

	return 
	;
}

ListNode* list_middle(ListNode *list)
{
	ListNode *middle = list;
	int len = 0;
	ListNode *cur = list;
	while(cur != NULL)
	{
		++len;
		cur = cur->next;		
	}

	cur = list;
	int step = len/2;
	while(--step>0)
		middle = middle->next;
	
	return middle;
}

ListNode* create_list()
{
	ListNode* list = NULL, *tail = NULL;
	int A[] = {4,3,5,2,6,7,1};
	for(int i = 0; i < sizeof(A)/sizeof(A[0]); ++i)
	{
		ListNode *newNode = new ListNode(A[i]);
		if(list == NULL)
			list = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = tail->next;			
		}
	}

	return list;
}

void print_list(ListNode *list)
{
	ListNode *cur = list;
	while(cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

// ListNode* sort_list_norecursive(ListNode *list)