#include "../../../include/minishell.h"

void display_btree_node_child(t_btree_node *node)
{
	if (node == NULL)
	{
		printf("There is no NODE\n");
		return;
	}
	else if (node->lc == NULL && node->rc == NULL)
	{
		printf("NODE doesn't have child node\n");
		return;
	}
	else if (node->lc == NULL)
	{
		printf("(Empty) %s\n", node->rc->token->value);
		return;
	}
	else if (node->rc == NULL)
	{
		printf("%s (Empty)\n", node->lc->token->value);
		return;
	}

	printf("%s %s\n", node->lc->token->value, node->rc->token->value);
}

void display_btree_node_by_preorder(t_btree_node *node)
{
	if (node == NULL)
		return;
	printf("%s ", node->token->value);
	display_btree_node_by_preorder(node->lc);
	display_btree_node_by_preorder(node->rc);
}

void display_btree_by_preorder(t_btree *btree)
{
	printf("\npreorder start\n");
	display_btree_node_by_preorder(btree->root);
	printf("\npreorder end\n");
}
