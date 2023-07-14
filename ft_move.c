/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:15:51 by lortega-          #+#    #+#             */
/*   Updated: 2023/05/28 15:15:54 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	left(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x - 1] == 'C')
		vars->teat->rest--;
	if (vars->map[vars->player->y][vars->player->x - 1] == '1')
		return (1);
	else if (vars->map[vars->player->y][vars->player->x - 1] == 'E')
	{
		vars->map[vars->player->y][vars->player->x] = '0';
		vars->map[vars->player->y][vars->player->x - 1] = 'n';
		return (0);
	}
	else if (vars->map[vars->player->y][vars->player->x] == 'n')
	{
		vars->map[vars->player->y][vars->player->x - 1] = 'P';
		vars->map[vars->player->y][vars->player->x] = 'E';
		return (0);
	}
	vars->map[vars->player->y][vars->player->x] = '0';
	vars->map[vars->player->y][vars->player->x - 1] = 'P';
	return (0);
}

int	right(t_vars *vars)
{
	if (vars->map[vars->player->y][vars->player->x + 1] == 'C')
		vars->teat->rest--;
	if (vars->map[vars->player->y][vars->player->x + 1] == '1')
		return (1);
	else if (vars->map[vars->player->y][vars->player->x + 1] == 'E')
	{
		vars->map[vars->player->y][vars->player->x] = '0';
		vars->map[vars->player->y][vars->player->x + 1] = 'n';
		return (0);
	}
	else if (vars->map[vars->player->y][vars->player->x] == 'n' )
	{
		vars->map[vars->player->y][vars->player->x + 1] = 'P';
		vars->map[vars->player->y][vars->player->x] = 'E';
		return (0);
	}
	vars->map[vars->player->y][vars->player->x] = '0';
	vars->map[vars->player->y][vars->player->x + 1] = 'P';
	return (0);
}

int	moveup(t_vars *vars)
{
	if (vars->map[vars->player->y - 1][vars->player->x] == 'C')
		vars->teat->rest--;
	if (vars->map[vars->player->y - 1][vars->player->x] == '1' )
		return (1);
	else if (vars->map[vars->player->y - 1][vars->player->x] == 'E')
	{
		vars->map[vars->player->y][vars->player->x] = '0';
		vars->map[vars->player->y - 1][vars->player->x] = 'n';
		return (0);
	}
	else if (vars->map[vars->player->y][vars->player->x] == 'n')
	{
		vars->map[vars->player->y - 1][vars->player->x] = 'P';
		vars->map[vars->player->y][vars->player->x] = 'E';
		return (0);
	}
	vars->map[vars->player->y][vars->player->x] = '0';
	vars->map[vars->player->y - 1][vars->player->x] = 'P';
	return (0);
}

int	movedown(t_vars *vars)
{
	if (vars->map[vars->player->y + 1][vars->player->x] == 'C')
		vars->teat->rest--;
	if (vars->map[vars->player->y + 1][vars->player->x] == '1')
		return (1);
	if (vars->map[vars->player->y + 1][vars->player->x] == 'E')
	{
		vars->map[vars->player->y][vars->player->x] = '0';
		vars->map[vars->player->y + 1][vars->player->x] = 'n';
		return (0);
	}
	if (vars->map[vars->player->y][vars->player->x] == 'n')
	{
		vars->map[vars->player->y + 1][vars->player->x] = 'P';
		vars->map[vars->player->y][vars->player->x] = 'E';
		return (0);
	}
	vars->map[vars->player->y][vars->player->x] = '0';
	vars->map[vars->player->y + 1][vars->player->x] = 'P';
	return (0);
}
