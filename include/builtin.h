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
#define BUILTIN_H

#include "./struct.h"

/* in ../src/internal/builtin/ */
/* cd.c */
void	_invalid_err_cd(const char *str);
int		builtin_cd(char *directory);

/* echo.c */
int		builtin_echo(const char *str, int fd, int flag);

/* pwd.c */
int		builtin_pwd(void);

/* env.c */
void	builtin_env(void);

#endif
