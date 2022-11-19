#include "../../../include/minishell.h"

char	*get_prefix(char *str)
{
	char	*prefix;
	int		len;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '*')
		len++;
	if (len == 0)
		return (NULL);
	prefix = (char *)malloc(sizeof(char) * (len + 1 + 1));
	if (!prefix)
		return (NULL);
	ft_strlcpy(prefix, str, len + 1);
	return (prefix);
}

char	*get_suffix(char *str)
{
	char	*suffix;
	int		pre_len;
	int		suf_len;

	if (!str)
		return (NULL);
	pre_len = 0;
	while (str[pre_len] && str[pre_len] != '*')
		pre_len++;
	suf_len = ft_strlen(str) - pre_len - 1;
	if (suf_len == 0)
		return (NULL);
	suffix = (char *)malloc(sizeof(char) * (suf_len + 1 + 1));
	if (!suffix)
		return (NULL);
	ft_strlcpy(suffix, str + pre_len + 1, suf_len + 1);
	return (suffix);
}

void	token_replace(t_token **toklst, t_token *target, t_token *expans)
{
	t_token	*tmp;
	t_token	*tmp2;
	t_token	*tmp3;

	if (expans == NULL)
		return ;
	tmp = *toklst;
	if (tmp == target && tmp->next == NULL)
	{
		*toklst = expans;
	}
	while (tmp)
	{
		if (tmp->next == target)
		{
			tmp2 = tmp->next->next;
			tmp->next = expans;
			tmp3 = ft_tokenlast(expans);
			tmp3->next = tmp2;
		}
		tmp = tmp->next;
	}
}

t_token	*ft_tokenlast(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
