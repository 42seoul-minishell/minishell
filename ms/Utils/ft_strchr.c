/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:21:34 by bolee             #+#    #+#             */
/*   Updated: 2022/09/27 22:21:35 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*u_s;
	unsigned char	u_c;

	i = 0;
	u_s = (unsigned char *) s;
	u_c = (unsigned char) c;
	while (u_s[i] && u_s[i] != u_c)
		i++;
	if (u_s[i] == u_c)
		return ((char *) s + i);
	return (0);
}
