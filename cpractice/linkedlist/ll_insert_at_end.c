#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *root = NULL;

void insert(int);
void print_list(void);

int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	insert(80);
	insert(90);
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	insert(80);
	insert(90);

	print_list();

	return 0;
}

void insert(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
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
	struct node *temp =root;
	if(root == NULL)
	{
		printf("No nodes available in linked list");
	}
	else
	{
		while(temp != NULL)
		{
			printf("data in node:%d\n", temp->data);
			temp = temp->next;
		}
	}
}
