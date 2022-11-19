/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:08:00 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/19 00:28:21 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./base.h"
# include "./struct.h"
# include "./builtin.h"
# include "./utils.h"
# include "./core.h"
# include "./doublylist.h"
# include "./executor.h"
# include "./hashtable.h"
# include "./tokenizer.h"
# include "./error.h"
# include "./global.h"
# include "./syntax.h"
# include "./bintree.h"
# include "./expand.h"
# include "./parser.h"

t_global		*g_global;

#endif
