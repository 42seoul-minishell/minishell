/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../../include/minishell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:29:32 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/14 15:33:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_H
# define DOUBLYLIST_H

# include "./struct.h"

/* in ../src/internal/doublylist/ */
/* utils.c */
int				is_list_empty(t_doubly_list *lst);
void			display_list(t_doubly_list *lst);
t_type			check_type(t_type type);
t_doubly_node	*find_doubly_node(t_doubly_list *lst, char *str);

/* delete.c */
void			delete_doubly_node(t_doubly_list *lst, t_doubly_node *node);
void			find_delete_doubly_node(t_doubly_list *lst, char *str);
void			release_doubly_list(t_doubly_list *lst);

/* create.c */
t_token			*create_token(t_type type, char *value);
t_doubly_list	*create_doubly_list(void);
t_doubly_node	*create_doubly_node(t_token *token);

/* insert.c */
int				insert_node(t_doubly_list *lst, t_doubly_node *node);
int				insert_node_by_index(t_doubly_list *lst,
					t_doubly_node *node, size_t index);
					
/* read.c */
t_doubly_node	*get_node_by_index(t_doubly_list *lst, size_t idx);

#endif