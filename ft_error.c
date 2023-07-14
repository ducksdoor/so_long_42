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

void	ft_failchar(t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->aux[x] != '\0')
	{
		if (vars->aux[x] != '1' && vars->aux[x] != 'P'
			&& vars->aux[x] != 'C' && vars->aux[x] != '0'
			&& vars->aux[x] != 'E' && vars->aux[x] != '\n')
		{
			ft_print_error("Caracter extraño en el mapa.");
			exit(1);
		}
			x++;
	}
}

void	ft_errormap(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (vars->map[y] != '\0')
	{
		x = 0;
		while (vars->map[y][x] != '\0')
		{
			if (vars->map[y][0] != '1' || vars->map[y][vars->nx - 1] != '1' )
			{
				ft_print_error("No hay muros o el mapa no es rectangular");
				exit(1);
			}
			if (vars->map[0][x] != '1' || vars->map[vars->ny - 1][x] != '1')
			{
				ft_print_error("No hay muros o el mapa no es rectangular");
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	ft_error(t_vars *vars)
{
	int	x;
	int	p;
	int	e;

	x = 0;
	e = 0;
	p = 0;
	if (vars->teat->rest == 0)
	{
		ft_print_error("No tienes ningún coleccionable");
		exit(1);
	}
	while (vars->aux[x] != '\0')
	{
		if (vars->aux[x] == 'P')
			p++;
		if (vars->aux[x] == 'E')
			e++;
		x++;
	}
	if (p != 1 || e != 1)
	{
		ft_print_error("Personaje o Salida erronea");
		exit(1);
	}
}
