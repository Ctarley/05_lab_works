

#include "Node.h"

int main(int argc, char const *argv[])
{
	BOOL (WINAPI *is_dbg_present)();
	int result; 
	node *Node;
	int choise; 
	int value; 

	node* root = NULL;

	is_dbg_present = IsDebuggerPresent;
	if (IsDebuggerPresent())
	{
		result = 0;
	}
	else
	{
		print_tree(0, 0);
		if ( !IsDebuggerPresent() )
		{
			do
			{
				printf("\nWhat do you want to do?\n");
				printf("1.Insert\n");
				printf("2.Delete\n");
				printf("3.Show\n");
				printf("4.Inorder\n");
				printf("5.Preorder\n");
				printf("6.Postorder\n");
				printf("7.Exit\n");
				printf("Enter your choice:");
				scanf("%d", &choise);
				switch (choise)
				{
				case 1:
					printf("\nEnter The Data for Inserting:");
					scanf("%d", &value);
					printf("\nInserting!\n\n");
					if (root)
						tree_insert(root, value);
					else
						root = node_create(value);
					break;
				case 2:
					printf("\nEnter The Data for Deleting:");
					scanf("%d", &value);
					root = remove_node(root, value);
					break;
				case 3:
					print_tree(root, 0);
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
					is_dbg_present = IsDebuggerPresent;
					break;
				case 7:
					printf("\nExiting......");
					exit(1);
					return result;
				default:
					printf("Please Enter a valid number!!\n");
					break;
				}
			} while (!is_dbg_present());
		}
		result = 0;
	}
	return result;
}

