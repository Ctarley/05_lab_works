#include "Node.h"

void tree_insert(node* root, int key)
{
	if (root->key == key)
	{
		return;
	}
	DWORD time = GetTickCount();
	if (key < root->key)
	{
		if (GetTickCount() - time > 0x64)
			return;
		if (root->left == NULL)
			root->left = node_create(key);
		if ((root->left->key < key) && (!root->right))
		{
			int tmp = root->key;
			root->key = key;
			root->right = node_create(tmp);
			return;
		}
		if ((root->left->key > key) && (!root->right) && (!root->left->right))
		{
			int tmp = root->key;
			root->key = root->left->key;
			root->right = node_create(tmp);
			root->left = node_create(key);
		}

		tree_insert(root->left, key);
		return;
	}

	if (key > root->key)
	{
		if (root->right == NULL)
			root->right = node_create(key);
		if ((root->right->key > key) && (!root->left))
		{
			int tmp = root->key;
			root->key = key;
			root->left = node_create(tmp);
			return;
		}
		if ((root->right->key < key) && (!root->left) && (!root->right->left))
		{
			int tmp = root->key;
			root->key = root->right->key;
			root->left = node_create(tmp);
			root->right = node_create(key);
		}

		tree_insert(root->right, key);
		return;
	}
}

node* node_create(int key)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void print_tree(node *t, int u)
{
	if (t == NULL)
	{
		if (u == 0)
			printf("<Is Empty>\n");
		return;
	}
	else
	{
		print_tree(t->right, u+1);
		for (int i = 0;i<u;++i) printf("    ");
		if ((!t->left) && (!t->right))
			printf("<%d>\n", t->key);
		else
			printf("%d\n", t->key);
	}
	print_tree(t->left, u+1); 
}

void inorder_print(node *root)
{
	if (root == NULL)   // Базовый случай
	{
		return;
	}
	inorder_print(root->left);   //рекурсивный вызов левого поддерева
	printf("%d -> ", root->key);
	inorder_print(root->right);  //рекурсивный вызов правого поддерева
}

void preorder_print(node *root)
{
	if (root == NULL)   // Базовый случай
	{
		return;
	}
	printf("%d -> ", root->key);
	if ((!root->left) && (!root->right))
	{
		printf("Is empty");
		return;
	}
	preorder_print(root->left);   //рекурсивный вызов левого поддерева
	preorder_print(root->right);  //рекурсивный вызов правого поддерева
}

void postorder_print(node *root)
{
	if (root == NULL)   // Базовый случай
	{
		return;
	}
	if ((!root->left) && (!root->right))
	{
		printf("Is empty");
		//return;
	}
	postorder_print(root->left);   //рекурсивный вызов левого поддерева
	postorder_print(root->right);  //рекурсивный вызов правого поддерева
	printf("%d -> ", root->key);
}

node *remove_node(node* root, int x)
{
	node *t = new node;
	if (root == NULL)
		return NULL;
	if (x == root->key) {
		if (root->left == NULL) {
			t = root->right;
			free(root);
			return t;
		}
		t = root->left;
		while (t->right) {
			t = t->right;
		}
		t->right = root->right;
		return root->left;
	}
	if (x < root->key)
		root->left = remove_node(root->left, x);
	else
		root->right = remove_node(root->right, x);
	return root;
}

