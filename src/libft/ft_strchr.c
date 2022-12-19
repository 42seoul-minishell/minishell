/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:52:23 by bolee             #+#    #+#             */
/*   Updated: 2022/03/15 12:55:26 by bolee            ###   ########.fr       */
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
