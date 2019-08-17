#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_OBJECTS_IN_NODE 14

struct object_node {
	void *objects[14];
	int available_idx;
	struct object_node *next;
};


static struct object_node*
allocate_object_node ()
{
	struct object_node *node = malloc (sizeof(struct object_node));
	if (node == NULL) {
		printf("unable to allocate memory!\n");
		exit(0);
	}
	node->available_idx = 0;
	node->next = NULL;
	return node;
}

static void
update_node (struct object_node **cur_node, void *obj)
{
	struct object_node *cur = *cur_node;

	assert (cur->available_idx < MAX_OBJECTS_IN_NODE);
	cur->objects[cur->available_idx] = obj;
	cur->available_idx++;
	if (cur->available_idx == MAX_OBJECTS_IN_NODE) {
		cur->next = allocate_object_node ();
		*cur_node = cur->next;
	}
}

static void
add_to_objects_list (void *obj)
{
	static struct object_node *head = NULL, *cur = NULL;

	if (head == NULL) {
		cur = head = allocate_object_node ();
	}
	assert (head != NULL);
	assert (cur != NULL);
	update_node (&cur, obj);
}

void *mymalloc (int size)
{
	void *ret = malloc (size+4);
	((int*)ret)[0] = size;
	return (void*)(((char*)ret) + 4);
}

void abort ()
{
	printf("aborting due to null pointer dereference\n");
	exit (0);
}
