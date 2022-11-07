/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:31:59 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/03 18:32:27 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "./struct.h"

/* in ../src/internal/token/ */
/* split.c */
int				is_have(char *str, char sep);
void			split(t_doubly_list *lst, char *str, char sep);
int				split_quotes(t_doubly_list *lst, char *str);

/* token.c */
void			tokenizing(t_doubly_list *lst, char *str);

#endif