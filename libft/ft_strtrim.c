/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:44:51 by lortega-          #+#    #+#             */
/*   Updated: 2023/03/28 13:44:33 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_little_atoi(char const s1, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	if (s1 == 0)
		return (0);
	while (s1[start] && ft_little_atoi(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_little_atoi(s1[end -1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_strtrim("eeeeaaaatueresjaviaeaeaeaeaeaaaaeee", "ae"));
}*/
