/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:15:51 by lortega-          #+#    #+#             */
/*   Updated: 2023/05/28 15:15:54 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_strchr(const char *s, int c)
{
	int		x;
	int		y;

	if (!s)
		return (0);
	x = 0;
	y = ft_strlen(s);
	while (x <= y)
	{
		if (s[x] == (char)c)
		{
			return (1);
		}
		++x;
	}
	return (0);
}
