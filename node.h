// KIT107 Assignment 2
/*
 * Specification for the Node ADT
 * Author Julian Dermoudy
 * Version 22/3/2021
 *
 * THIS FILE IS COMPLETE
*/

#ifndef NODE_H
#define NODE_H

struct node_int;
typedef struct node_int *node;

void init_node(node *n, void *o);
void set_data(node n, void *o);
void set_next(node n1, node n2);
void *get_data(node n);
node get_next(node n);

#endif