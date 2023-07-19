/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:39:41 by lortega-          #+#    #+#             */
/*   Updated: 2023/03/30 14:47:02 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
		newstr[k++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		newstr[k++] = s2[i++];
	newstr[k] = '\0';
	free((char *)s1);
	return (newstr);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%s", ft_strjoin("lorem ipsum", "dolor sit amet"));
}*/
