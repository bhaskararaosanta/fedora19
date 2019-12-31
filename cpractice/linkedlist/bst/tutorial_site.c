#include <stdio.h>
#include <stdlib.h>

struct bstnode {
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

struct bstnode *insert(struct bstnode *localroot, int value)
{
	struct bstnode *temp = (struct bstnode *)malloc(sizeof(struct bstnode));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;

	if(localroot == NULL) {
		localroot = temp;
		return localroot;
	}
	else if(value <= localroot->data) {
		localroot->left = insert(localroot->left, value);
	}
	else {
		localroot->right = insert(localroot->right, value);
	}
	return localroot;
}

void inorder(struct bstnode *traverse)
{
	if(traverse == NULL) {
		return;
	}
	inorder(traverse->left);
	printf("%d ->", traverse->data);
	inorder(traverse->right);
}

int main()
{
	struct bstnode *root = NULL;
	root = insert(root, 8);
	insert(root, 3);
	insert(root, 1);
	insert(root, 6);
	insert(root, 7);
	insert(root, 10);
	insert(root, 14);
	insert(root, 4);

	inorder(root);

	return 0;
}
