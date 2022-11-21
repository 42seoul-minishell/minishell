/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:47:25 by bolee             #+#    #+#             */
/*   Updated: 2022/11/19 14:09:40 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "./struct.h"

/* extract.c */
char	*extract_double_quotes(char **str);
char	*extract_brackets(char **str, char open, char close);
char	*extract_pipe(char **str);

/* token.c */
void	tokenizer(t_doubly_list *lst, char *str);

/* utils.c */
int		is_operator(char *str);
int		is_quote(char *str);
int		is_double_operator(char *str);
void	white_to_space(char *str);

/* clean.c */
int		check_space_around(char *str, char *start);
char	*make_clean_sentence(char *str);

t_tType	verify_double_quote(char *str);
t_tType	verify_single_quote(char *str);

t_tType	verify_token(char *str);

t_tType	verify_input_redir(char *str);
t_tType	verify_output_redir(char *str);

t_tType	verify_pipe(char *str);

t_tType	verify_bracket(char *str);

#endif
