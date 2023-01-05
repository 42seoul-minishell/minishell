/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:29 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:30 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "base.h"

typedef enum e_token_type
{
	NONE,
	OR,
	AND,
	PIPE,
	CMD,
	OPTION,
	D_QUOTE,
	S_QUOTE,
	INP_RDIR,
	OUT_RDIR,
	APP_RDIR,
	HERE_DOC,
	BRACKET,
}	t_tType;

typedef enum e_node_type
{
	TN_NONE,
	TN_OR,
	TN_AND,
	TN_PIPE,
	TN_HEREDOC,
	TN_RDIR,
	TN_WORD,
}	t_tnType;

/* token structure */
typedef struct s_token
{
	t_tType			type;
	char			*value;
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

/* bintree node */
typedef struct s_bintree_node
{
	t_tnType				type;
	t_list					*token_lst;
	int						fd[2];
	struct s_bintree_node	*lc;
	struct s_bintree_node	*rc;
}	t_bintree_node;

/* bintree structure */
typedef struct s_bintree
{
	t_bintree_node	*root;
}	t_bintree;

/* pipe structure */
typedef struct s_pipe
{
	pid_t	pid;
	int		cnt;
	int		fd[2];
	int		prev;
	int		status;
}	t_pipe;

/* structure includes all other structures */
typedef struct s_global
{
	t_hashtable		*envp;
	char			**envp_arr;
	char			*origin_path;
	FILE			*fp;
	t_bintree		*tree;
	int				heredoc_cnt;
	int				status;
	int				fd_stdin;
	int				fd_stdout;
	struct termios	nodisplay_set;
	struct termios	display_set;
}	t_global;

/* structure for wildcard */
typedef struct s_wildcard
{
	char	**path_token;
	char	*token_value;
	t_list	lst;
	size_t	lst_size;
}	t_wildcard;

#endif
