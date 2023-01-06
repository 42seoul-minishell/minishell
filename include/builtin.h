/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:32:29 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:32:30 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "struct.h"

/* in ../src/internal/builtin/ */
/* cd.c */
int		builtin_cd(t_list *lst, int out_fd);

/* echo.c */
int		builtin_echo(t_list *lst, int out_fd);

/* env.c */
void	builtin_env(int out_fd);

/* exit.c */
void	builtin_exit(t_list *lst);

/* export.c */
int		builtin_export(t_list *lst, int out_fd);

/* pwd.c */
int		builtin_pwd(int out_fd);

/* unset.c */
void	builtin_unset(t_list *lst);

#endif
