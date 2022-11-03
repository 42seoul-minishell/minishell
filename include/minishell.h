/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 14:46:37 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* standard header */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>

/* GNU readline header */
# include <readline/readline.h>
# include <readline/history.h>

/* libft header */
# include "libft/libft.h"

/* macros */
# define TRUE 1
# define FALSE 0
# define MAGIC_NUMBER 5381

/* external variable for environment variables */
extern char	**environ;

/* token type enumerate */
typedef enum e_type
{
	T_NULL = 1,
	T_WORD,
	T_PIPE,
	T_REDIRECT,
	T_DOUBLE_QUOTES,
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

/* in ../src/internal/btree/ */
/* insert.c */
int				insert_lc_node(t_btree_node *parent, t_token *token);
int				insert_rc_node(t_btree_node *parent, t_token *token);
/* create.c */
t_btree			*create_btree(void);
t_btree_node	*create_btree_node(t_token *token);
/* delete.c */
void			delete_btree_node_child(t_btree_node *parent);
int				delete_btree_node_lc(t_btree_node *parent);
int				delete_btree_node_rc(t_btree_node *parent);
/* utils.c */
void			display_btree_node_child(t_btree_node *node);
void			display_btree_node_by_preorder(t_btree_node *node);
void			display_btree_by_preorder(t_btree *btree);
/* read.c */
t_btree_node	*get_btree_node_by_id(t_btree_node *node, int id);

/* in ../src/internal/builtin/ */
/* cd.c */
void			_invalid_err_cd(const char *str);
int				builtin_cd(char *directory);
/* echo.c */
int				builtin_echo(const char *str, int fd, int flag);
/* pwd.c */
int				builtin_pwd(void);
/* env.c */
void			builtin_env(t_doubly_list *lst);

/* in ../src/internal/hashmap/ */
/* create.c */
t_ht_item		*create_ht_item(char *key, char *value);
t_hashtable		*create_hashtable(size_t size);
/* insert.c */
void			hash_insert(t_ht_item *new_item, t_hashtable *table);
/* utils.c */
char			*get_key_from_env(char *str);
char			*get_value_from_env(char *env);
void			display_hashtable(t_hashtable *table);
void			prevent_collision(t_hashtable *table, size_t hash, \
							t_ht_item *new_item);
/* hashtable.c */
t_hashtable		*parse_env_to_hashtable(char **env);
size_t			hash_index(char *key, size_t size);
/* delete.c */
void			delete_item(t_ht_item *item);
void			delete_table(t_hashtable *table);
/* search.c */
char			*search(t_hashtable *table, char *key);

/* in ../src/internal/core/ */
/* prompt.c */
char			*create_prompt(void);
/* signal.c */
void			sig_handler(int signal);
void			setting_signal(void);

/* in ../src/internal/token/ */
/* split.c */
int				is_have(char *str, char sep);
void			split(t_doubly_list *lst, char *str, char sep);
/* token.c */
void			tokenizing(t_doubly_list *lst, char *str);

#endif
