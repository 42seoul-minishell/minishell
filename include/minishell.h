/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/10/18 13:09:27 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef enum e_type
{
	T_NULL = 1,
	T_WORD,
	T_PIPE,
	T_REDIRECT,
	T_DOUBLE_QUOTES,
}	t_type;

typedef struct s_enviroment_list
{
	char	*env_token;
	char	*path;
}	t_env_list;

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

/* btree node */
typedef struct s_btree_node
{
	int					id;
	t_token				*token;
	struct s_btree_node	*lc;
	struct s_btree_node	*rc;
}	t_btree_node;

/* btree structure */
typedef struct s_btree
{
	t_btree_node	*root;
}	t_btree;

/* in ../src/internal/doublylist/utils.c */
int				is_list_empty(t_doubly_list *lst);
void			display_list(t_doubly_list *lst);
t_type			switch_type(t_type type);
t_doubly_node	*find_doubly_node(t_doubly_list *lst, char *str);

/* in ../src/internal/doublylist/delete.c */
void			delete_doubly_node(t_doubly_list *lst, t_doubly_node *node);
void			find_delete_doubly_node(t_doubly_list *lst, char *str);
void			release_doubly_list(t_doubly_list *lst);

/* in ../src/internal/doublylist/create.c */
t_token			*create_token(t_type type, char *value);
t_doubly_list	*create_doubly_list(void);
t_doubly_node	*create_doubly_node(t_token *token);

/* in ../src/internal/doublylist/insert.c */
int				insert_node(t_doubly_list *lst, t_doubly_node *node);
int				insert_node_by_index(t_doubly_list *lst, \
t_doubly_node *node, size_t index);
/* in ../src/internal/doublylist/read.c */
t_doubly_node	*get_node_by_index(t_doubly_list *lst, size_t idx);

/* in ../src/internal/btree/insert.c */
int				insert_lc_node(t_btree_node *parent, t_token *token);
int				insert_rc_node(t_btree_node *parent, t_token *token);

/* in ../src/internal/btree/create.c */
t_btree			*create_btree(void);
t_btree_node	*create_btree_node(t_token *token);

/* in ../src/internal/btree/delete.c */
void			delete_btree_node_child(t_btree_node *parent);
int				delete_btree_node_lc(t_btree_node *parent);
int				delete_btree_node_rc(t_btree_node *parent);

/* in ../src/internal/btree/utils.c */
void			display_btree_node_child(t_btree_node *node);
void			display_btree_node_by_preorder(t_btree_node *node);
void			display_btree_by_preorder(t_btree *btree);

/* in ../src/internal/btree/read.c */
t_btree_node	*get_btree_node_by_id(t_btree_node *node, int id);

/* in ../src/internal/builtin/cd.c */
void			_invalid_err_cd(const char *str);
int				builtin_cd(char *directory);
/* in ../src/internal/builtin/echo.c */
int				builtin_echo(const char *str, int fd, int flag);
/* in ../src/internal/builtin/pwd.c */
int				builtin_pwd(void);

/* in ../src/internal/builtin/env.c */
void			builtin_env(t_doubly_list *lst);
#endif
