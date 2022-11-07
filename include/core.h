/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:33:29 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/03 18:33:30 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "./struct.h"

/* in ../src/internal/core/ */
/* prompt.c */
char			*create_prompt(void);

/* signal.c */
void			sig_handler(int signal);
void			setting_signal(void);

#endif