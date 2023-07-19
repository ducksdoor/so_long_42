/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:11:44 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/22 21:13:56 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_ptr(unsigned long nb)
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

int	ft_ptr2(unsigned long nb)
{
	int	x;

	x = ft_len_ptr(nb);
	if (nb >= 16)
	{
		ft_ptr2(nb / 16);
		ft_ptr2(nb % 16);
	}
	else if (nb == 0)
		ft_putchar('0');
	else if (nb > 9 && nb < 16)
		ft_putchar((nb - 10) + 'a');
	else if (nb <= 9 && nb > 0)
		ft_putchar(nb + '0');
	return (x);
}

int	ft_ptr(unsigned long nb)
{
	int	x;

	write(1, "0x", 2);
	x = ft_ptr2(nb);
	x = x + 2;
	return (x);
}
