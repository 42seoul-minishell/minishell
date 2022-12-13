/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:09 by bolee             #+#    #+#             */
/*   Updated: 2022/12/13 13:35:10 by bolee            ###   ########.fr       */
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
# include "./wildcard.h"

t_global		*g_global;

#endif
