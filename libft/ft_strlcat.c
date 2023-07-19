/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:24:40 by lortega-          #+#    #+#             */
/*   Updated: 2023/03/30 14:47:39 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	y = 0;
	x = ft_strlen(dst);
	while (src[y] != '\0' && x + 1 < dstsize)
	{
		dst[x] = src[y];
		++x;
		++y;
	}
	dst[x] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[y]));
}
/*
#include <stdio.h>
#include <string.h>
int main (void)
{
	char	dest[100] = "muchaspatatas";
	char	src[100] = "caliente";
	int		size = 7;

	printf("%zu\n", ft_strlcat(dest, src, size));
	printf("%lu\n", strlcat(dest, src, size));
}
*/
