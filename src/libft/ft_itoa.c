/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:23:53 by bolee             #+#    #+#             */
/*   Updated: 2022/03/11 15:09:03 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	find_size(long long n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static long long	find_for_div(long long n)
{
	long long	i;
	long long	size;
	long long	for_div;

	i = 1;
	for_div = 1;
	size = find_size(n);
	while (i < size)
	{
		for_div *= 10;
		i++;
	}
	return (for_div);
}

static void	put_in_res(char *res, long long n)
{
	char		tmp;
	long long	for_div;

	for_div = find_for_div(n);
	while (for_div != 0)
	{
		tmp = 48 + n / for_div;
		*res++ = tmp;
		n %= for_div;
		for_div /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*res;
	long long	size;
	long long	num;

	if (n < 0)
	{
		num = (long long) n * -1;
		size = find_size(num);
		res = (char *)ft_malloc((size + 2) * sizeof(char));
		res[0] = '-';
		res[size + 1] = '\0';
		put_in_res(res + 1, num);
	}
	else
	{
		size = find_size((long long) n);
		res = (char *)ft_malloc((size + 1) * sizeof(char));
		res[size] = '\0';
		put_in_res(res, (long long) n);
	}
	return (res);
}
