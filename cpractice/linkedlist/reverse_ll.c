#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *insert_begin(struct node *localroot, int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	printf("size of node:%d\n", sizeof(struct node));
	temp->data = value;
	temp->next = NULL;
	if(localroot == NULL) {
		localroot = temp;
		return localroot;
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
	printf("size of node:%d\n", sizeof(struct node));
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

struct node *reverse_list(struct node *localroot)
{
	struct node *before = NULL;
	struct node *current = localroot, *after = localroot;
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

void print_list(struct node *localroot)
{
	struct node *traverse = localroot;
	if(localroot == NULL) {
		printf("No nodes created yet\n");
		return;
	}
	else {
		while(traverse != NULL) {
			printf("%d->", traverse->data);
			traverse = traverse->next;
		}
		printf("\n");
		return;
	}
}



int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 300);
	root = insert_begin(root, 200);
	root = insert_begin(root, 100);
	root = insert_end(root, 400);
	root = insert_end(root, 500);

	print_list(root);
	root = reverse_list(root);
	print_list(root);
	root = reverse_list(root);
	print_list(root);

	return 0;
}
