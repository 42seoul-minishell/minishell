/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:58:19 by bolee             #+#    #+#             */
/*   Updated: 2022/09/21 21:58:20 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

// 토큰을 파서 트리에 매다는 함수
void    add(t_tree  **tree, t_token *token)
{
  // 토큰을 노드로 생성
  t_node *new = create_node(token);
  // 루트 토큰 구하기
  t_token *st = (*tree)->root->token;

  // 루트의 토큰의 우선 순위가 추가할 토큰의 우선 순위보다 크거나 같은지 판별
  // 만약 크거나 같다면 root가 현재 노드의 자식 노드로 들어가고 현재 노드를 root로 갱신
  if (compare_type(st, token))
  {
    new->lc = (*tree)->root;
    (*tree)->root = new;
  }
  else
  {
    // 루트의 토큰의 우선 순위가 추가할 토큰의 우선 순위보다 작은 경우
    (*tree)->root->rc = new;
  }
}

// 파싱하는 함수
t_tree    *parsing(t_tokens *tokens)
{
    t_tree  *tree;

    tree = create_tree();
    // 첫 번째 토큰으로 노드를 생성해 root에 설정
    tree->root = create_node(tokens->token);
    tokens = tokens->next;
    // 반복해서 모든 토큰을 파서 트리에 추가
    while (tokens)
    {
        add(&tree, tokens->token);
        tokens = tokens->next;
    }
    return (tree);
}
