/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:27:34 by bolee             #+#    #+#             */
/*   Updated: 2022/10/05 16:41:39 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

// 노드 생성 함수
t_node	*create_node(t_token *token)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->token = token;
	node->lc = NULL;
	node->rc = NULL;
	return (node);
}

// 트리 생성 함수
t_tree	*create_tree()
{
	t_tree	*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	if (tree == NULL)
		exit(1);
	tree->root = NULL;
	return (tree);
}

// 자식 노드 데이터 출력
void	print_chlid(t_node *node)
{
	if (node == NULL)
	{
		printf("노드가 없습니다.\n");
		return ;
	}
	else if (node->lc == NULL && node->rc == NULL)
	{
		printf("자식 노드가 없습니다.\n");
		return ;
	}
	else if (node->lc == NULL)
	{
		printf("왼쪽 자식 노드가 없습니다.\n");
		printf("(Empty) %s\n", node->rc->token->str);
		return ;
	}
	else if (node->rc == NULL)
	{
		printf("오른쪽 자식 노드가 없습니다.\n");
		printf("%s (Empty)\n", node->lc->token->str);
		return ;
	}

	printf("%s %s\n", node->lc->token->str, node->rc->token->str);
}

// Preorder 운행법으로 노드의 문자열을 출력하는 함수
// 트리 운행법(Treaversal): 트리를 구성하는 각 노드를 찾아가는 방법
/*
  - Preorder 운행법: Root -> Left -> Right
  - Inorder 운행법: Left -> Root -> Right
  - Postorder 운행법: Rigth -> Root -> Left
*/
void	print_node_by_preorder(t_node *node)
{
	if (node == NULL)
		return ;
	printf("%s ", node->token->str);
	print_node_by_preorder(node->lc);
	print_node_by_preorder(node->rc);
}

// tree preorder로 출력
void	preorder_tree(t_tree *tree)
{
	printf("\npreorder 시작\n");
	print_node_by_preorder(tree->root);
	printf("\npreorder 끝\n");
}

// 노드 내 문자열 갱신 함수
void	update_node_data(t_node *node, char *str)
{
	node->token->str = str;
}

// 왼쪽 자식 노트 삽입
void	insert_lc_node(t_node *parent, t_token *token)
{
	parent->lc = create_node(token);
	if (parent->lc == NULL)
		exit(1);
}

// 오른쪽 자식 노트 삽입
void	insert_rc_node(t_node *parent, t_token *token)
{
	parent->rc = create_node(token);
	if (parent->rc == NULL)
		exit(1);
}

// 어떠한 노드의 자식과 그 서브트리(하위 자식들) 모두 삭제
void	delete_all_child(t_node *parent)
{
	if (parent == NULL)
		return ;
	delete_all_child(parent->lc);
	delete_all_child(parent->rc);
	free(parent->token->str);
	free(parent->token);
	free(parent);
}

// 왼쪽 자식 노드와 해당 노드의 서브트리 삭제
void	delete_lc(t_node *parent)
{
	if (parent == NULL)
	{
		printf("노드가 없습니다.\n");
		return ;
	}
	if (parent->lc == NULL)
	{
		printf("왼쪽 자식 노드가 없습니다.\n");
		return ;
	}
	delete_all_child(parent->lc);
	parent->lc = NULL;
}

// 오른쪽 자식 노드와 해당 노드의 서브트리 삭제
void	delete_rc(t_node *parent)
{
	if (parent == NULL)
	{
		printf("노드가 없습니다.\n");
		return ;
	}
	if (parent->rc == NULL)
	{
		printf("오른쪽 자식 노드가 없습니다.\n");
		return ;
	}
	delete_all_child(parent->rc);
	parent->rc = NULL;
}
