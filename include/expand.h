/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:58:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 16:59:35 by mingkim          ###   ########.fr       */
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