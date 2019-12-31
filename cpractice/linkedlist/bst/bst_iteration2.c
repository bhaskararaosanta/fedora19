#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *leftchild;
	struct node *rightchild;
};
/*
struct node *insert(struct node *locroot, int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->leftchild = temp->rightchild = NULL;
	if(locroot == NULL) {
		locroot = temp;
		return locroot;
	}
	else {
		struct node *current = locroot;
		struct node *parent = NULL;
		while(current != NULL) {
			parent = current;
			if(value < parent->data) {
				current = current->leftchild;
			}
			else {
				current = current->rightchild;
			}
		}
		if(value < parent->data) {
			parent->leftchild = temp;
		}
		else {
			parent->rightchild = temp;
		}
		return locroot;
	}
}*/
struct node *insert(struct node *locroot, int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->leftchild = temp->rightchild = NULL;
	if(locroot == NULL) {
		locroot = temp;
		return locroot;
	}
	if(value < locroot->data) {
		locroot->leftchild = insert(locroot->leftchild, value);
	}
	else {
		locroot->rightchild = insert(locroot->rightchild, value);;
	}
	return locroot;
}

void inorder(struct node *locroot)
{
	if(locroot == NULL) {
		return;
	}
	inorder(locroot->leftchild);
	printf("%d -> ", locroot->data);
	inorder(locroot->rightchild);
}


int main()
{
	struct node *root = NULL;
	root = insert(root, 40);
	root = insert(root, 400);
	root = insert(root, 30);
	root = insert(root, 500);
	root = insert(root, 800);
	root = insert(root, 60);

	inorder(root);


	return 0;
}
