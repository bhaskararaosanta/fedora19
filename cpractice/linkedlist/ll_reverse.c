#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int dataext;
	struct node *next;
};

struct node *root = NULL;

void insert(int, int);
void print_list(void);
void reverse_list(void);

int main()
{
	int data1, data2;
	insert(10, 100);
	insert(20, 200);
	insert(30, 300);
	insert(40, 400);
	insert(50, 500);
	insert(60, 600);
	insert(70, 700);
	insert(80, 800);
	insert(90, 900);
	print_list();
	reverse_list();
	print_list();
	return 0;


}

void insert(int data, int dataext)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->dataext = dataext;
	temp->next = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *temp1 = root;
		while(temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}

void print_list(void)
{
	struct node *temp = root;
	if(temp == NULL)
	{
		printf("There are no nodes in linked list\n");
	}
	else
	{
		struct node *temp1 = root;
		while(temp1 != NULL)
		{
			printf("data items in node are:%d %d and address of node:%p\n", temp1->data, temp1->dataext, temp1);
			temp1 = temp1->next;
		}
	}
}

void reverse_list(void)
{
	struct node *old = NULL;
	struct node *curr = root;
	struct node *new = NULL;

	if(curr == NULL)
	{
		printf("no nodes available to reverse\n");
	}
	else
	{
		while(curr != NULL)
		{
			/* store next */
			new = curr->next;
			/* reverse current node's pointer */
			curr->next = old;
			/* move pointer one position ahead */
			old = curr;
			curr = new;
		}
		root = old;
	}
}

