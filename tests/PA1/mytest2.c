#include <stdio.h>
#include "support.h"

struct node 
{
	int val;
	struct node * next;
};

int main(int argc, char const *argv[])
{
	struct node * head = (struct node * ) mymalloc(sizeof(struct node));
	struct node * curr = head;
	for (int i=0 ; i<10; i++)
	{
		curr->val = i+5;
		curr->next = (struct node * )mymalloc(sizeof(struct node));
		curr = curr->next;
	}
	curr = head;
	int i = 5;
	int sum = 0;
	while (i>0)
	{
		sum += curr->val;
		curr = curr->next;
		i--;
	}
	printf("%d\n",sum);
	return 0;
}
