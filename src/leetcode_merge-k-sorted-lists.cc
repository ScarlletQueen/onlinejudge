/**
 * Definition for singly-linked list.
 */
 #include <stdio.h>
 #include <vector>
 using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

    	if(lists.empty()) return NULL;
    	
    	printf("list size = %d\n", lists.size());

    	ListNode *result = lists[0];

    	for(size_t i = 1; i < lists.size(); ++i)
    	{
    		result = mergeTwoLists(result, lists[i]);
    	}

    	return result;
    }

    ListNode *mergeTwoLists(ListNode *listA, ListNode *listB)
    {
    	ListNode head(-1); // this head makes life easy!
    	ListNode *tail = &head;

    	while(listA != NULL && listB != NULL)
    	{
    		ListNode *p = NULL;
    		if(listA->val < listB->val)
    		{
    			p = listA;
    			listA = listA->next;
    		}
    		else
    		{
    			p = listB;
    			listB = listB->next;
    		}

    		// thanks for the head, no need to check if it's first node
    		tail->next = p;  
    		tail = tail->next;
    	}

    	if(listA != NULL)
    		tail->next = listA;
    	if(listB != NULL)
    		tail->next = listB;

    	return head.next;
    }

    void print_list(ListNode *list)
    {
    	while(list != NULL)
    	{
    		printf("%d \n", list->val);
    		list = list->next;
    	}
    	printf("\n");
    }
};

int main()
{
	vector<ListNode *> lists;
	ListNode *listA = NULL;
	ListNode *listB = new ListNode(1);
	lists.push_back(listA);
	lists.push_back(listB);

	Solution sln;
	sln.mergeKLists(lists);
}