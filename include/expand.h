/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:47 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:34:48 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "base.h"
# include "struct.h"

void	expand(t_doubly_list *lst);
void	idx_is_not_zero(char **str, int *i, char *add);
void	idx_is_zero(char **str, int *i, char *add);

#endif
