/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:05:39 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/06 13:36:02 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	s;

	x = 0;
	s = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (x < len && haystack[x] != '\0')
	{
		if (haystack[x] == needle[0])
		{
			s = 1;
			while (needle[s] != '\0' && x + s < len
				&& haystack[x + s] == needle[s])
				s++;
			if (needle[s] == '\0')
				return ((char *)&haystack[x]);
		}
		++x;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", ft_strnstr("paelella", "ell", 20));
	printf("%s\n", strnstr("paelella", "ell", 19));
}*/
