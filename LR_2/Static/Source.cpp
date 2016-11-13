#include "Node.h"

int main(int argc, char const *argv[])
{
	if (argc <= 4)
	{
		printf("Usage: %s <count of insert data> <insert data> <action>\n", argv[0]);
		return 1;
	}

	
	int cnt = atoi(argv[1]);
	int* data = (int*)malloc(cnt);
	for(int i=0;i<cnt;i++)
		data[i] = atoi(argv[2+i]);
	int action = atoi(argv[2+cnt]);

	node* root = NULL;

	printf("%d\n", cnt);

	printf("\nWhat do you want to do?\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Show\n");
	printf("4.Inorder\n");
	printf("5.Preorder\n");
	printf("6.Postorder\n");
	printf("7.Exit\n");
	printf("Enter your choice:\n");


	for(int i=0;i<cnt;i++)
	{
		if (root)
			tree_insert(root, data[i]);
		else
			root = node_create(data[i]);
	}

	switch (action)
	{
	case 1:
		break;
	case 2:
		//root = remove_node(root, value);
		break;
	case 3:
		break;
	case 4:
		printf("\n");
		inorder_print(root);
		printf("\n");
		break;
	case 5:
		printf("\n");
		preorder_print(root);
		printf("\n");
		break;
	case 6:
		printf("\n");
		if ( root )
		{
			postorder_print(root);
		}
		else
		{
		printf("Is empty");
		}
		printf("\n");
		break;
	case 7:
		printf("\nExiting......");
		exit(1);
	default:
		printf("Please Enter a valid number!!\n");
		break;
	}

	print_tree(root, 0);

	return 0;
}

