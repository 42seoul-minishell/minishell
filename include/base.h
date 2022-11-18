/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:12:59 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/16 16:14:20 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

/* standard header */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <fcntl.h>
# include <stdarg.h>
# include <termios.h>
/* GNU readline header */
# include <readline/readline.h>
# include <readline/history.h>

/* libft header */
# include "libft/libft.h"

/* macros */
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define MAGIC_NUMBER 5381
# define DISPLAY 1
# define NODISPLAY 0
# define SYNTAXERR	"syntax error near unexpected token `"

/* external variable for environment variables */
extern char	**environ;

#endif