#include "../../../../include/minishell.h"

void	idx_is_not_zero(char **str, int *i, int j, char *add)
{
	char	*tmp;
	char	*front;
	char	*back;

	front = ft_substr(*str, 0, i);
	back = ft_substr(*str, *i + j + 1, \
		ft_strlen(*str) - *i - j - 1);
	tmp = ft_strjoin(front, add);
	free(front);
	free(add);
	free(*str);
	check_single_pointer(tmp);
	*str = ft_strjoin(tmp, back);
	free(tmp);
	free(back);
	check_single_pointer(*str);
	if (j != 1)
		*i += j;
}

void	idx_is_zero(char **str, int *i, int j, char *add)
{
	char	*tmp;
	char	*back;

	back = ft_substr(*str, *i + j + 1, \
		ft_strlen(*str) - *i - j - 1);
	free(*str);
	*str = ft_strjoin(add, back);
	free(back);
	free(add);
	check_single_pointer(*str);
	if (j != 1)
		*i += j;
}
