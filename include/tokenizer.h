/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:45 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:45 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "struct.h"

/* check.c */
size_t	is_pair_double_quotes(char *str);
size_t	is_pair_single_quotes(char *str);

/* tokenizer.c */
void	tokenizer(t_doubly_list *lst, char *str);

/* utils.c */
ssize_t	get_operator_length(char *str);
int		is_operator(char *str);
int		is_quote(char *str);
int		is_double_operator(char *str);

/* verify_quotes.c */
t_tType	verify_double_quote(char *str);
t_tType	verify_single_quote(char *str);

/* verify_token.c */
t_tType	verify_token(char *str);

/* verify_redir.c */
t_tType	verify_input_redir(char *str);
t_tType	verify_output_redir(char *str);

/* verify_pipes.c */
t_tType	verify_pipe(char *str);

/* relocation_doulby_lst.c */
void	relocation_doubly_lst(t_doubly_list *lst);

#endif
