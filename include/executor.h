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

# include "./struct.h"

/* executor.c */
void	executor(t_bintree_node	*root);
int		serve_status(char *cmd);

void	execute_and(t_bintree_node *node);
void	execute_or(t_bintree_node *node);

/* bracket.c */
int		execute_bracket(t_bintree_node *root);

void execute_command(t_bintree_node *node);


int	exec_word(t_bintree_node *root);
int	exec_last_word_child(t_bintree_node *root, t_pipe p);
int	exec_word_child(t_bintree_node *root);

void heredoc_redirect(t_bintree_node *node, char *eof, int *save_fd);

int execute_pipe(t_bintree_node *node);

void	execute_redirect(t_bintree_node *node);

#endif
