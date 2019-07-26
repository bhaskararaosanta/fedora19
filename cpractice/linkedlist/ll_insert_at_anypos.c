#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head;

void Insert(int x)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(head != NULL)
		temp->next = head;
	head = temp;
}

void Print(void)
{
	struct Node *temp = head;
	printf("List is:");
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

int main()
{
	int n, i, x;
	head = NULL;
	printf("How many numbers\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter data to be placed inside node:");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
	return 0;
}
