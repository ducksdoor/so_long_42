/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:17:15 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/23 20:53:52 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ismayus(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (0);
	return (0);
}

int	ft_len_nbr_hx(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (len + 1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_hx(unsigned int n, char const s)
{
	int	x;
	int	p;

	x = ft_len_nbr_hx(n);
	p = ft_ismayus(s);
	if (n >= 16)
	{
		ft_putnbr_hx(n / 16, s);
		ft_putnbr_hx(n % 16, s);
	}
	else if (n == 0)
		ft_putchar('0');
	else if (n > 9 && n < 16 && p == 1)
		ft_putchar((n - 10) + 'A');
	else if (n > 9 && n < 16 && p == 0)
		ft_putchar((n - 10) + 'a');
	else if (n <= 9 && n > 0)
		ft_putchar(n + '0');
	return (x);
}
