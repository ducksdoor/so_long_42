/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:01:34 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/23 20:53:35 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flags(va_list args, char object)
{
	int	len;

	len = 0;
	if (object == 'c')
		len += ft_putchar((va_arg(args, int)));
	if (object == 's')
		len += ft_putstr((va_arg(args, char *)));
	if (object == 'd' || object == 'i')
		len += ft_putnbr((va_arg(args, int)));
	if (object == '%')
		len += ft_putchar('%');
	if (object == 'x' || object == 'X')
		len += ft_putnbr_hx((va_arg(args, unsigned int)), object);
	if (object == 'p')
		len += ft_ptr((va_arg(args, unsigned long)));
	if (object == 'u')
		len += ft_positivenumber((va_arg(args, unsigned int)));
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	int		x;
	va_list	args;

	x = 0;
	len = 0;
	va_start(args, str);
	while (str[x] != '\0')
	{
		if (str[x] == '%')
		{
			x++;
			len += ft_flags(args, str[x]);
		}
		else
			len += ft_putchar(str[x]);
		if (str[x])
			x++;
	}
	va_end(args);
	return (len);
}
