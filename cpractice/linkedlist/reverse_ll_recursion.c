
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

//struct Node *head;

struct Node *Insert(struct Node *localhead, int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(localhead == NULL) localhead = temp;
	else{
		struct Node *temp1 = localhead;
		while(temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return localhead;
}

void Print(struct Node *localhead)
{
	while(localhead != NULL)
	{
		printf("%d ", localhead->data);
		localhead = localhead->next;
	}
}

struct Node *Reverse(struct Node *localhead)
{
	struct Node *current, *prev, *next;
	current = localhead;
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	localhead = prev;
	return localhead;
}


int main()
{
	struct Node *head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);

	return 0;
}

