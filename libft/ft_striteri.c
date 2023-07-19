/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:19:44 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/04 15:17:37 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		x;

	if (!s || !f)
		return ;
	x = 0;
	while (s[x] != '\0')
	{
		f(x, &s[x]);
		x++;
	}
}
/*
#include <stdio.h>
#include <string.h>

void ft_toupper5(unsigned int s, char *c)
{
	if (s >= 0)
	{
		if (c[0] >= 'a' && c[0] <= 'z')
			c[0] = c[0] - 32;
	}
}



int main(void)
{
	char	s[] = "castania pilonga";
	char	x;

	x = 0;
	ft_striteri(s, ft_toupper5);
	printf("%s", s);
	return (0);
}*/
