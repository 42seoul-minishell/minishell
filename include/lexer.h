/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:18:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 16:19:14 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "./struct.h"

/* in ../src/internal/lexer/ */
/* lexer.c */
void	lexer(char *str);

/* check.c */
int		is_have(char *str, char sep);
int		is_space_around_operator(char *str);
size_t	is_pair_bracket(char *str, char open, char close);
size_t	is_pair_double_quotes(char *str);

#endif