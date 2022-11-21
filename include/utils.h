/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:26:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/20 00:33:36 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

/* in src/utils/ */
/* utils.c */
void	free_pointers(size_t length, ...);
void	ft_display_ctrlx_set(int flag);
void	sig_exec(int sig);
int		check_status(int status);

/* verify_utils.c */
int		str_parens(char *str, int i);
int		is_have(char *str, char sep);

/* tokenizer_utils.c */
char	*safe_malloc(size_t idx);
int		safe_insert(t_doubly_list *lst, t_tType type, char *str);
int		is_only_space(char *str);

/* malloc_tuils.c */
void	*sp_malloc(size_t size);
void	*dp_malloc(size_t size);

#endif
