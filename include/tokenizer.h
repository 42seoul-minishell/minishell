/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:47:25 by bolee             #+#    #+#             */
/*   Updated: 2022/11/17 20:33:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "./struct.h"

/* in ../src/internal/token/ */
/* split.c */
// int				is_have(char *str, char sep);
// size_t			is_pair(char *str, char sep);
// void			split(t_doubly_list *lst, char *str, char sep);
// int				split_quotes(t_doubly_list *lst, char *str);

/* extract.c */
char			*extract_double_quotes(char **str);
char			*extract_brackets(char **str, char open, char close);
char			*extract_pipe(char **str);

/* token.c */
void			tokenizer(t_doubly_list *lst, char *str);

/* utils.c */
int				is_operator(char *str);
int				is_double_operator(char *str);
int				is_space(char c);
t_tType			type_casting(char *str);
int				safe_insert(t_doubly_list *lst, t_tType type, char *str);

/* clean.c */
int				check_space_around(char *str, char *start);
char			*make_clean_sentence(char *str);

t_tType			verify_quote_token(char *str);
t_tType			verify_token(char *str);
#endif
