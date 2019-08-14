#include <stdio.h>
#include <stdlib.h>

struct list {
	int info;
	struct list *next;
};

int cmp(struct list *node1, struct list *node2)
{
	return node1->info == node2->info;
}

struct list* find(struct list *head, int val, int (*cmp)(struct list *node1, struct list *node2))
{
	struct list *cur = head;
	struct list aux;

	aux.info = val;
	while (cur) {
		if (cmp(cur, &aux)) {
			return cur;
		}
	}
	return NULL;
}


struct list* insert(struct list *head, int val)
{
	struct list *node = (struct list*)malloc(sizeof(struct list));

	if (node == NULL) {
		return NULL;
	}
	node->info = val;
	node->next = head;
	return node;
}


int main ()
{
	struct list *head[100];
	int i, sum = 0;

	for (i = 0; i < 100; i++) {
		head[i] = insert(NULL, i);
		sum += (head[i] == NULL) ? 0 : head[i]->info;
	}
	return sum;
}
