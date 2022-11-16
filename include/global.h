/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:14:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 15:19:44 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "base.h"
# include "struct.h"

t_global	*create_global(t_doubly_list *lst, t_hashtable *envp);

#endif