#include <stdio.h>
//#include <stdlib.h>
#include "linkedlist.h"


int main()
{
	Node *head = create_node(12);
	append_node(head, create_node(20));
	head = prepend_node(head, create_node(30));
	printf("Head is:%d\n", get_node_val(head));
	set_node_val(head, 32);
	print_all(head);
	head = delete_node(head, 32);
	if(search_node(head, 20)) {
		printf("%d found\n", 20);
	}
	print_all(head);
	//free_all(head);
	return 0;
}

