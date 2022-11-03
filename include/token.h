/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../../include/minishell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:26 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 14:10:41 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "./struct.h"

/* in ../src/internal/token/ */
/* split.c */
int				is_have(char *str, char sep);
void			split(t_doubly_list *lst, char *str, char sep);
/* token.c */
void			tokenizing(t_doubly_list *lst, char *str);

#endif