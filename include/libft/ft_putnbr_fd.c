/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:39:05 by bolee             #+#    #+#             */
/*   Updated: 2022/03/11 14:52:29 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	find_for_div(long long n)
{
	long long	i;
	long long	size;
	long long	for_div;

	i = 1;
	size = 1;
	if (n)
	{
		size = 0;
		while (n)
		{
			n /= 10;
			size++;
		}
	}
	for_div = 1;
	while (i < size)
	{
		for_div *= 10;
		i++;
	}
	return (for_div);
}

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	long long	num;
	char		tmp[12];
	long long	for_div;

	i = 0;
	num = n;
	if (n < 0)
	{
		tmp[i++] = '-';
		num *= -1;
	}
	for_div = find_for_div(num);
	while (for_div)
	{
		tmp[i++] = num / for_div + '0';
		num %= for_div;
		for_div /= 10;
	}
	tmp[i] = '\0';
	ft_putstr_fd(tmp, fd);
}
