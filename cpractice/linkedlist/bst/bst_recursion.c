#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *leftchild;
	struct node *rightchild;
};

struct node *root = NULL;

void insert(int vale)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->leftchild = temp->rightchild = NULL;
	struct node *current, *parent;

	// if root is empty
	if(root == NULL) {
		root = temp;
	}
	else {
		current = root;
		parent = NULL;
		while(1) {
			parent = current;
			// goto left of the tree
			if(value < parent->data) {
				current = current->leftchild;
				
