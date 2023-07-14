/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:23:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/07/06 19:23:16 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_print_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	ft_ber(t_vars *vars, char *av)
{
	int	x;

	vars->file = av;
	x = ft_strlen (vars->file)-4;

	if (ft_strncmp (vars->file + x, ".ber", 4) != 0)
	{
		ft_print_error("El mapa no acaba en \".ber\"");
		exit (1);
	}
	return ;
}

void	ft_finish(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'n' && vars->teat->rest <= 0)
			{
				ft_printf("\n**********\nHas Ganado\n**********\n");
				exit(1);
			}
			if (vars->teat->rest != 0)
				return ;
			x++;
		}
		y++;
	}
	return ;
}
