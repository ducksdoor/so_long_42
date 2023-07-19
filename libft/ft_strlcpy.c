/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:05:08 by lortega-          #+#    #+#             */
/*   Updated: 2023/03/15 11:12:57 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while ((src[x] != '\0') && (x < size -1))
		{
			dst[x] = src[x];
			++x;
		}
		dst[x] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char	dest[] = "pocacosa";
	char	src[] = "muchascosas";
	int	size  = 5;
	printf("%zu\n",ft_strlcpy(dest, src, size));
	printf("%s \n", dest);


	printf("%lu", strlcpy(dest, src, size));
}*/
