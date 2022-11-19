#include "../../include/minishell.h"

void	*sp_malloc(ssize_t size)
{
	void	*tmp;

	tmp = (void *)malloc(size);
	if (!tmp)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (tmp);
}

void	*dp_malloc(ssize_t size)
{
	void 	**tmp;

	tmp = (void **)malloc(size);
	if (!tmp)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (tmp);
}
