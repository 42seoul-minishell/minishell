/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:50 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:51 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

/* in src/utils/ */
/* utils.c */
void	display_ctrlx_set(int flag);
void	sig_exec(int sig);
int		check_status(int status);

/* verify_utils.c */
int		str_parens(char *str, int i);
int		is_have(char *str, char sep);

/* tokenizer_utils.c */
int		safe_insert(t_doubly_list *lst, t_tType type, char *str);
int		is_only_space(char *str);

/* malloc_tuils.c */
void	*sp_malloc(size_t size);
void	**dp_malloc(size_t size);
void	free_dp(void **dp);

#endif
