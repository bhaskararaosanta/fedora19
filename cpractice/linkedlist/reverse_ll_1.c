#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *insert_begin(struct node *localroot, int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
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
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->next = NULL;
	if(localroot == NULL) {
		localroot = temp;
		return localroot;
	}
	else {
		struct node *traverse = localroot;
		while(traverse->next != NULL) {
			traverse = traverse->next;
		}
		traverse->next = temp;
		return localroot;
	}
}

void print_list(struct node *localroot)
{
	if(localroot == NULL) {
		printf("No nodes created in list till now\n");
		return;
	}
	else {
		struct node *traverse = localroot;
		while(traverse != NULL) {
			printf("%d ->", traverse->data);
			traverse = traverse->next;
		}
		printf("\n");
		return;
	}
}

void reverse_print(struct node *traverse)
{
	//struct node *traverse = localroot;

	if(traverse == NULL) {
		return;
	}
	reverse_print(traverse->next);
	printf("%d ->", traverse->data);
}

int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 30);
	root = insert_begin(root, 20);
	root = insert_begin(root, 10);
	root = insert_end(root, 40);
	root = insert_end(root, 50);

	print_list(root);
	
	reverse_print(root);
	printf("\n");

	return 0;
}
