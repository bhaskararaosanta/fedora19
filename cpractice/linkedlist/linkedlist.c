#include <stdio.h>
#include <stdlib.h>

#define	DEBUG

struct node {
	int data;
	struct node *next;
};

struct node *insert_begin(struct node *localroot, int value)
{
	struct node *traverse = localroot;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
#ifdef	DEBUG
	{
		printf("address of localroot	:%p\n", localroot);
		printf("address of temp		:%p\n", temp);
	}
#endif
	temp->data = value;
	temp->next = NULL;
	if(localroot == NULL) {
		return temp;
	}
	else {
		temp->next = localroot;
		localroot = temp;
		return localroot;
	}
}

struct node *insert_end(struct node *localroot, int value)
{
	struct node *traverse = localroot;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
#ifdef	DEBUG
	{
		printf("address of localroot	:%p\n", localroot);
		printf("address of temp		:%p\n", temp);
	}
#endif
	temp->data = value;
	temp->next = NULL;
	if(localroot == NULL) {
		return temp;
	}
	else {
		while(traverse->next != NULL) {
			traverse = traverse->next;
		}
		traverse->next = temp;
		return localroot;
	}
}

void print_list(struct node *localroot)
{
	struct node *traverse = localroot;
#ifdef	DEBUG
	{
		printf("address of localroot	:%p\n", localroot);
		printf("address of traverse	:%p\n", traverse);
	}
#endif
	if(localroot == NULL) {
		printf("No nodes created yet in linked list.\n");
		return;
	}
	else {
		while(traverse != NULL) {
			printf("%d -> ", traverse->data);
			traverse = traverse->next;
#ifdef	DEBUG
	{
		printf("address in  traverse	:%p\n", traverse);

	}
#endif
		}
		printf("\n");
		return;
	}
}

struct node *reverse_list(struct node *localroot)
{
	struct node *before = NULL;
	struct node *current = localroot;
	struct node *after = localroot;
#ifdef	DEBUG
	{
		printf("address of before	:%p\n", before);
		printf("address of current	:%p\n", current);
		printf("address of after	:%p\n", after);
	}
#endif
	after = after->next;
	current->next = NULL;
	while(after != NULL) {
		before = current;
		current = after;
		after = after->next;
		current->next = before;
	}
	return current;
}


int main()
{
	struct node *root = NULL;
#ifdef	DEBUG
	{
		printf("address of root	:%p\n", root);
	}
#endif
	root = insert_begin(root, 300);
	root = insert_begin(root, 200);
	root = insert_begin(root, 100);
	root = insert_end(root, 400);
	root = insert_end(root, 500);

	print_list(root);
	root = reverse_list(root);
	print_list(root);

	return 0;
}
