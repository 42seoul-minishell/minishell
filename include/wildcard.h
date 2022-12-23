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

/* util.c */
void	lstinsort(t_list *lst, t_list *new_lst, int (*cmp)(const char *p1, const char *p2, size_t size));
char	*wildcard_join(t_wildcard *wc);

#endif
