/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:32:51 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:32:52 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_H
# define DOUBLYLIST_H

# include "./struct.h"

/* in ../src/internal/doublylist/ */
/* utils.c */
int				is_list_empty(t_doubly_list *lst);
void			display_list(t_doubly_list *lst);
t_tType			check_type(t_tType type);
t_doubly_node	*find_doubly_node(t_doubly_list *lst, char *str);

/* delete.c */
void			delete_doubly_node(t_doubly_list *lst, t_doubly_node *node);
void			find_delete_doubly_node(t_doubly_list *lst, char *str);
void			release_doubly_list(t_doubly_list *lst);
void			release_doubly_node(t_doubly_node *node);

/* create.c */
t_token			*create_token(t_tType type, char *value);
t_doubly_list	*create_doubly_list(void);
t_doubly_node	*create_doubly_node(t_token *token);

/* insert.c */
int				insert_node(t_doubly_list *lst, t_doubly_node *node);
int				insert_node_by_index(t_doubly_list *lst,
					t_doubly_node *node, size_t index);

/* read.c */
t_doubly_node	*get_node_by_index(t_doubly_list *lst, size_t idx);

#endif
