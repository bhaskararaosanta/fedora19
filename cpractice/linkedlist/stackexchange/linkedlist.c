#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <stddef.h>

struct Node {
	int value;
	struct Node *next;
};

int get_node_val(const Node *node) 
{
	return node->value;
}

void set_node_val(Node *node, int val) 
{
	node->value = val;
}

static size_t node_size(void) 
{
	return sizeof(struct Node);
}

static void *allocate_node(void) 
{
	return malloc(node_size());
}

Node *create_node(int data)
{
	Node *new_node;
	if((new_node = allocate_node()) == NULL) {
		//gracefully_handle_failure();
	}

	new_node->value = data;
	new_node->next = NULL;
	return new_node;
}

Node *append_node(Node *head, Node *to_add)
{
	if(head == NULL) {
		return NULL;
	}
	Node *current = head;
	while(current->next) {
		current = current->next;
	}
	current->next = to_add;
	to_add->next = NULL;
	return head;
}

Node *prepend_node(Node *head, Node *to_add)
{
	to_add->next = head;
	head = to_add;
	return head;
}

Node *search_node(const Node *head, int search_val)
{
	for(const Node *current = head; current != NULL; current = current->next) {
		if(current->value == search_val) {
			return (Node *)current;
		}
	}
	return NULL;
}

Node *delete_node(Node *head, int delete_val)
{
	Node **indirect = &head;
	while((*indirect)->value != delete_val) {
		indirect = &(*indirect)->next;
	}
	*indirect = (*indirect)->next;
	return head;
}

void print_all(const Node *head)
{
	for(const Node *current = head; current != NULL; current = current->next) {
		printf("%d -> ", current->value);
	}
	puts("NULL");
}

void free_all(Node *head)
{
	for(Node *current = head; current != NULL; current = current->next) {
		free(head);
	}
}

