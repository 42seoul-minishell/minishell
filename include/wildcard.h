/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:31:02 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:54 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H

# include "struct.h"

/* in src/internal/wildcard/ */
/* wildcard.c */
void	wildcard(t_doubly_list *lst);

/* nothing_have.c */
char	*nothing_have(char *d_name);
int		is_have_suffix(char *d_name, char *suffix);

/* only_prefix.c */
char	*only_prefix(char *d_name, char *prefix);

/* only_suffix.c */
char	*only_suffix(char *d_name, char *suffix);

/* both_have.c */
char	*both_have(char *d_name, t_wildcard *wildcard);

/* util.c */
char	*get_prefix(char *str);
char	*get_suffix(char *str);
char	*join_with_blank(char *str1, char *str2);
char	*wildcard_join(char **split);
DIR		*get_dir_pointer(t_wildcard	*wildcard);

#endif
