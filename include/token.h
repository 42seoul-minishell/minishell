/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:47:25 by bolee             #+#    #+#             */
/*   Updated: 2022/11/04 15:47:27 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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

#endif
