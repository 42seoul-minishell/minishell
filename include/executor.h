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
void	executor(t_bintree_node *root, int in_fd, int out_fd);
int		serve_status(char *cmd);

/* and_or.c */
void	execute_and(t_bintree_node *node);
void	execute_or(t_bintree_node *node);

/* bracket.c */
void	execute_bracket(t_bintree_node *node);

/* builtin.c */
int		check_builtin(t_list *lst);
int		execute_builtin(t_list *lst, int out_fd);

/* cammand.c */
int		execute_command(t_bintree_node *node, int in_fd, int out_fd);

/* pipe.c */
void	execute_pipe(t_bintree_node *node, int in_fd, int out_fd);
void	set_heredoc(t_bintree_node *node);

#endif
