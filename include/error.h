/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:29 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:34:31 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "struct.h"

/* in ../src/error/ */
/* error.c */
void	exit_error(const char *str);
void	syntax_error(const char *str, int flag);
void	not_found_error(const char *str);
void	no_file_direct_error(const char *str1, const char *str2);

#endif
