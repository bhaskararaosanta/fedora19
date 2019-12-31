#include <stdio.h>
#include <stdlib.h>

struct bstnode {
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

struct bstnode *insert(struct bstnode *locroot, int value)
{
	struct bstnode *temp = (struct bstnode *)malloc(sizeof(struct bstnode));
	temp->data = value;
	temp->left = temp->right = NULL;

	if(locroot == NULL) {
		locroot = temp;
		return locroot;
	}
	else {
		struct bstnode *current = locroot;
		struct bstnode *parent = NULL;
		while(1) {
			parent = current;
			if(value < current->data) {
				current = current->left;
				if(current == NULL) {
					parent->left = temp;
					return;
				}
			}
			else {
				current = current->right;
				if(current == NULL) {
					parent->right = temp;
					return;
				}
			}
		}
	}
}

void inorder(struct bstnode *locroot)
{
	if(locroot == NULL) {
		return;
	}
	inorder(locroot->left);
	printf(" %d -> ", locroot->data);
	inorder(locroot->right);
}

int main()
{
	struct bstnode *root = NULL;
	root = insert(root, 100);
	insert(root, 200);
	insert(root, 300);
	insert(root, 400);
	insert(root, 500);

	inorder(root);

	return 0;
}
