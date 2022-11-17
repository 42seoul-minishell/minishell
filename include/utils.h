/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:26:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/17 21:06:32 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

void	free_pointers(size_t length, ...);
void	ft_display_ctrlx_set(int flag);
void	sig_exec(int sig);
int		check_status(int status);
int		str_parens(char *str, int i);
#endif