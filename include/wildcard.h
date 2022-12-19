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

/* case.c */
char	*nothing_have(char *d_name);
char	*only_prefix(char *d_name, char *prefix);
char	*only_suffix(char *d_name, char *suffix);
char	*both_have(char *d_name, t_wildcard *wildcard);

/* util.c */
char	*get_prefix(char *str);
char	*get_suffix(char *str);

#endif
