/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../../include/minishell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:15:15 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 14:44:11 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "./struct.h"

/* in ../src/internal/core/ */
/* prompt.c */
char			*create_prompt(void);
/* signal.c */
void			sig_handler(int signal);
void			setting_signal(void);

#endif