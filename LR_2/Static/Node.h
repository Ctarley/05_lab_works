#ifndef _NODE_H
#define _NODE_H

#include <malloc.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <Winbase.h>

struct node
{
	int key;
	//const char* value;
	node* left;
	node* right;
};


void tree_insert(node* root, int key);
node* node_create(int key);
void print_tree(node *t, int u);
void inorder_print(node *root);
void preorder_print(node *root);
void postorder_print(node *root);
node* remove_node(node* root, int x);

#endif
