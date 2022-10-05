/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:58:07 by bolee             #+#    #+#             */
/*   Updated: 2022/09/27 21:58:08 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "Lexer.h"

void	syntax_pipeline(t_tokens *tokens);
void	syntax_cmd(t_tokens *tokens);
void	syntax_redirects(t_tokens *tokens);
int     syntax_io_redirect(t_tokens *tokens);
int     syntax_simple_cmd(t_tokens *tokens);

#endif
