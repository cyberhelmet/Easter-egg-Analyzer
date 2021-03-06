// KIT107 Assignment 2
/*
* Implementation for Node
* Author Julian Dermoudy
* Version 22/3/2021
*
* THIS FILE IS COMPLETE
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node_int
{
	void *data;
	node next;
};

/*
* 'Constructor' for node
*/
void init_node(node *n, void *o)
{
	*n = (node)malloc(sizeof(struct node_int));
	(*n)->data = o;
	(*n)->next = NULL;
}

/*
* Getter for data
* Return data field
*/
void *get_data(node n)
{
	return (n->data);
}

/*
* Getter for next
* Return next field
*/
node get_next(node n)
{
	return (n->next);
}

/*
* Setter for data
* Param o value to be placed into the node's data field
*/
void set_data(node n, void *o)
{
	n->data = o;
}

/*
* Setter for next
* Param n2 value to be placed into the node's next field
*/
void set_next(node n1, node n2)
{
	n1->next = n2;
}
