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
void	executor(t_bintree_node *root);
// int		run_execute(char *cmd);
int		serve_status(char *cmd);
int		serve_status(char *cmd);

/* bracket.c */
int		execute_bracket(t_bintree_node *root);
#endif
