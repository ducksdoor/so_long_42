/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:19:17 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/06 13:28:19 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		x;
	int		y;
	char	*des;

	x = ft_strlen(src);
	y = 0;
	des = (char *)malloc(sizeof(char) * (x + 1));
	if (des == NULL)
		return (0);
	while (src[y] != '\0')
	{
		des[y] = src[y];
		++y;
	}
	des[y] = '\0';
	return (des);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char	*pepito= "caramelodementa";
	char	*pepito2="caramelodementa";
	
	printf("%s", ft_strdup(pepito));
	printf("%s", strdup(pepito2));
}
*/
