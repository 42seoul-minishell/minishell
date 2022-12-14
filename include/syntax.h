/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:35 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:36 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "struct.h"

/* syntax.c */
int		syntax(t_doubly_list *lst);

/* set_bintree.c */
void	set_bintree(t_doubly_list *lst, t_doubly_node *node);

/* utils.c*/
int		set_bintree_type(t_list *token_list);

/* token_list.c */
void	relocate_token_list(t_list **token_list);
t_list	*set_token_list(t_doubly_list *lst, t_doubly_node **node);

#endif
