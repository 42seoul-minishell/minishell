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

void delete_doubly_node(t_doubly_node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node->token->value);
    free(node->token);
    free(node);
}

void find_delete_doubly_node(t_doubly_list *lst, char *str)
{
    t_doubly_node *node;

    node = find_doubly_node(lst, str);
    if (node == NULL)
        return;
    delete_doubly_node(node);
}

void release_doubly_list(t_doubly_list *lst)
{
    t_doubly_node *node;
    t_doubly_node *tmp;
    t_doubly_node *delete;

    node = lst->header.next;
    if (node != NULL)
    {
        printf("3\n");
        tmp = node->next;
        while (tmp != node)
        {
            delete = tmp;
            tmp = tmp->next;
            free(delete->token->value);
            free(delete->token);
            free(delete);
        }
        free(node->token->value);
        free(node->token);
        free(node);
    }
    free(lst);
}
