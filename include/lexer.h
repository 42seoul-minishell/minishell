/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:18:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/14 15:07:17 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "./struct.h"

void	lexer(char *str);
int		is_space_around_operator(char *str);
size_t	is_pair_bracket(char *str, char open, char close);
size_t	is_pair_double_quotes(char *str);

#endif