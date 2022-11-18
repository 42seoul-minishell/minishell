/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:12:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/18 17:06:05 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "./struct.h"

/* in ../src/error/ */
/* error.c */
void	check_single_pointer(void *pointer);
void	check_double_pointer(void **pointer);
void	exit_on_error(const char *str);
void	print_error(char *format, ...);

#endif
