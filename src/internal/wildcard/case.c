#include "../../../include/minishell.h"

int	case_zero(char *d_name, t_token *token, t_token **expan_token)
{
	t_token	*new;
	t_token	input;
	int		res;

	res = 0;
	input.content = ft_strdup(d_name);
	input.type = token->type;
	new = new_token(input);
	if (new->content)
		add_token(expan_token, new);
	return (res);
}

int	case_one(char *d_name, char *prefix, t_token *token, t_token **expan_token)
{
	t_token	*new;
	t_token	input;
	int		res;

	res = 0;
	if (ft_strncmp(d_name, prefix, ft_strlen(prefix)) == 0)
	{
		input.content = ft_strdup(d_name);
		input.type = token->type;
		new = new_token(input);
		if (new->content)
			add_token(expan_token, new);
	}
	return (res);
}

int	case_two(char *d_name, char *suffix, t_token *token, t_token **expan_token)
{
	int		pos;
	t_token	*new;
	t_token	input;
	int		res;

	res = 0;
	pos = ft_strlen(d_name) - ft_strlen(suffix);
	if (pos < 0)
		res = -1;
	if (strncmp(d_name + pos, suffix, ft_strlen(suffix)) == 0)
	{
		input.content = ft_strdup(d_name);
		input.type = token->type;
		new = new_token(input);
		if (new->content)
			add_token(expan_token, new);
	}
	return (res);
}

int	case_three(char *d_name, t_aster *ast, t_token *token, t_token **expans)
{
	int		pos;
	t_token	*new;
	t_token	input;
	int		res;

	res = 0;
	if (ft_strncmp(d_name, ast->prefix, ft_strlen(ast->prefix)) == 0)
	{
		pos = ft_strlen(d_name) - ft_strlen(ast->suffix);
		if (pos < 0)
			res = -1;
		if (strncmp(d_name + pos, ast->suffix, ft_strlen(ast->suffix)) == 0)
		{
			input.content = ft_strdup(d_name);
			input.type = token->type;
			new = new_token(input);
			if (new->content)
				add_token(expans, new);
		}
	}
	return (res);
}
