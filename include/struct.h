/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:13:05 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/09 21:13:23 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./base.h"

/* token type enumerate */
typedef enum e_type
{
	T_NULL = 1,
	T_CMD,
	T_PIPE,
	T_REDIRECT,
	T_DOUBLE_QUOTES,
	T_BRACKET,
}	t_type;

/* token structure */
typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

/* node of double linked list */
typedef struct s_doubly_node
{
	t_token					*token;
	struct s_doubly_node	*prev;
	struct s_doubly_node	*next;
}	t_doubly_node;

/* double linked list */
typedef struct s_doubly_list
{
	t_doubly_node	header;
	size_t			len;
}	t_doubly_list;

/* hashtable item structure */
typedef struct s_ht_item
{
	char					*key;
	char					*value;
	struct s_ht_item		*next;
}	t_ht_item;

/* hashtable structure */
typedef struct s_hashtable
{
	t_ht_item		**items;
	size_t			size;
	size_t			count;
}	t_hashtable;

#endif