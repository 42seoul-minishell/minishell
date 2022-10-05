/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:42:45 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/05 16:51:01 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void    delete_one(t_doubly_node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node->token->value);
    free(node->token);
    free(node);
}

void    find_delete(t_doubly_list *lst, char *str)
{
    t_doubly_node   *node;

    node = find_node(lst, str);
    if (node == NULL)
        return ;
    delete_one(node);
}

void    release_list(t_doubly_list *lst)
{
    t_doubly_node   *node;
    t_doubly_node   *delete;

    node = lst->header.next;
    while (node != NULL)
    {
        delete = node;
        node = node->next;
        free(delete->token->value);
        free(delete->token);
        free(delete);
    }
    free(lst);
}
