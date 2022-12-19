/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:32:39 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:32:40 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "struct.h"

/* in ../src/internal/core/ */
/* prompt.c */
char			*create_prompt(void);

/* signal.c */
void			sig_handler(int signal);
void			setting_signal(void);

#endif
