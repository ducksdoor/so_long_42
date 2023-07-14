/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goodmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:37:09 by lortega-          #+#    #+#             */
/*   Updated: 2023/07/14 20:41:29 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_really_full(t_vars *vars)
{
	int	x;
	int	y;
	int	fail;

	y = 0;
	fail = 0;
	while (vars->foo[y] != '\0')
	{
		x = 0;
		while (vars->foo[y][x] != '\0')
		{
			if (vars->foo[y][x] == 'E' || vars->foo[y][x] == 'C')
			{
				ft_print_error("No puedes llegar a un items");
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	ft_full(t_vars *vars, int y, int x)
{
	if ((vars->foo[y][x - 1] != 'P') && (vars->foo[y][x - 1] != '1'))
	{
		vars->foo[y][x - 1] = 'P';
		ft_full(vars, y, x - 1);
	}
	if ((vars->foo[y - 1][x] != 'P') && (vars->foo[y - 1][x] != '1'))
	{
		vars->foo[y - 1][x] = 'P';
		ft_full (vars, y - 1, x);
	}
	if ((vars->foo[y][x + 1] != 'P') && (vars->foo[y][x + 1] != '1'))
	{
		vars->foo[y][x + 1] = 'P';
		ft_full(vars, y, x + 1);
	}
	if ((vars->foo[y + 1][x] != 'P') && (vars->foo[y + 1][x] != '1'))
	{
		vars->foo[y + 1][x] = 'P';
		ft_full (vars, y + 1, x);
	}
}

void	ft_goodmap(t_vars *vars)
{
	int	y;
	int	x;

	y = 1;
	while (vars->foo[y] != '\0')
	{
		x = 1;
		while (vars->foo[y][x] != '\0')
		{
			if (vars->foo[y][x] == 'P')
				ft_full(vars, y, x);
			x++;
		}
		y++;
	}
	ft_really_full(vars);
}
