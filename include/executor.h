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
void	executor(t_bintree_node *root, int in_fd, int out_fd, int is_pipe);

/* and_or.c */
void	execute_and(t_bintree_node *node);
void	execute_or(t_bintree_node *node);

/* bracket.c */
void	execute_bracket(t_bintree_node *node);

/* builtin.c */
int		check_builtin(t_list *lst);
int		execute_builtin(t_list *lst, int out_fd);

/* cammand.c */
void	execute_command(t_bintree_node *node, \
						int in_fd, int out_fd, int is_pipe);

/* pipe.c */
void	execute_pipe(t_bintree_node *node, int in_fd, int out_fd);
void	set_heredoc(t_bintree_node *node);

/* wait.c */
void	wait_child(void);
int		get_pipe_status(void);
int		check_status(int status);

/* utils.c */
size_t	get_token_size(t_list *token_lst);
char	**token_list_to_array(t_list *token_lst);
char	*get_abs_path(char *cmd);

/* command_utils.c */
void	run_cmd(char *abs_path, char *argv[]);
int		set_in(t_bintree_node *node, int in_fd);
int		set_out(t_bintree_node *node, int out_fd);

#endif
