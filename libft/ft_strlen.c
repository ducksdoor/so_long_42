/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:58:13 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/06 13:12:06 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char	*x = NULL;
//	printf("%zu", strlen(NULL));
	printf("%zu", ft_strlen(x));
}*/
