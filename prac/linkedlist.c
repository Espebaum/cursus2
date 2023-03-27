#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			num;
	struct node	*next;	
}	t_node;

typedef struct list
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_list;

//node
t_node	*new_node(t_node *node, int data)
{
	node = (t_node *) malloc(sizeof(t_node));
	node->num = data;
	node->next = NULL;
	return (node);
}

// list
void	init_list(t_list *list)
{
	list->head = (t_node *) malloc(sizeof(t_node));
	list->tail = (t_node *) malloc(sizeof(t_node));
	list->head->num = -1;
	list->head->next = list->tail;
	list->tail->num = -1;
	list->tail->next = NULL;
	list->size = 0;
}

void	insert(t_list *list, int data)
{
	t_node	*node;
	t_node	*curr;

	node = NULL;
	node = new_node(node, data);
	curr = list->head;
	while (curr->next != list->tail)
		curr = curr->next;
	curr->next = node;
	node->next = list->tail;
	list->size++;
}

void	print_list(t_list *list)
{
	t_node	*curr;

	curr = list->head;
	while (curr->next)
	{
		printf("num : %d\n", curr->num);
		curr = curr->next;
	}
}

int	main(void)
{
	t_list	list;

	init_list(&list);
	insert(&list, 100);
	print_list(&list);
}
