/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:38 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:34:39 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "struct.h"

/* executor.c */
void	init_fd(int fd[]);
void	executor(t_bintree_node	*root, int sup_fd[], int dir);
int		serve_status(char *cmd);

/* and_or.c */
void	execute_and(t_bintree_node *node, int sup_fd[], int dir);
void	execute_or(t_bintree_node *node, int sup_fd[], int dir);

/* bracket.c */
int		execute_bracket(t_bintree_node *root, int sup_fd[], int dir);

/* cammand.c */
void	execute_command(t_bintree_node *node, int fd[], int sup_fd[], int dir);

/* double_quotes.c */
int		exec_word(t_bintree_node *root);
int		exec_last_word_child(t_bintree_node *root, t_pipe p);
int		exec_word_child(t_bintree_node *root);

/* heredoc_redirect.c */
void	heredoc_redirect(t_bintree_node *node, char *eof, int *save_fd);

/* pipe.c */
int		execute_pipe(t_bintree_node *node, int fd[]);

/* redirect.c */
void	execute_redirect(t_bintree_node *node, int fd[]);

#endif
