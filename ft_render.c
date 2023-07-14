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

void	ft_middle_render(t_vars *vars, char **map, int i, int j)
{
	char	*w;
	char	*vpi;
	char	*vti;

	vpi = vars->player->img;
	vti = vars->teat->img;
	w = vars->window;
	mlx_put_image_to_window(vars->mlx, w, vars->floor, i * 64, j * 64);
	if (map[j][i] == '1')
		mlx_put_image_to_window(vars->mlx, w, vars->box, i * 64, j * 64);
	if (map[j][i] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, w, vpi, i * 64, j * 64);
		vars->player->x = i;
		vars->player->y = j;
	}
	if (map[j][i] == 'C')
		mlx_put_image_to_window(vars->mlx, w, vti, (i * 64 + 9), (j * 64 + 9));
	if (map[j][i] == 'E')
	{
		if (vars->teat->rest > 0)
			mlx_put_image_to_window(vars->mlx, w, vars->door, i * 64, j * 64);
		if (vars->teat->rest <= 0)
			mlx_put_image_to_window(vars->mlx, w, vars->door2, i * 64, j * 64);
	}
}

void	ft_finish_render(t_vars *vars, int i, int j)
{
	char	*vpi;
	char	*w;

	w = vars->window;
	vpi = vars->player->img;
	mlx_put_image_to_window(vars->mlx, w, vars->door, i * 64, j * 64);
	mlx_put_image_to_window(vars->mlx, vars->window, vpi, i * 64, j * 64);
	vars->player->x = i;
	vars->player->y = j;
	return ;
}

int	render(t_vars *vars)
{
	int		i;
	int		j;
	char	*moves;
	char	**map;

	j = 0;
	map = vars->map;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			ft_middle_render(vars, map, i, j);
			if (map[j][i] == 'n')
				ft_finish_render(vars, i, j);
			i++;
		}
		j++;
	}
	moves = ft_itoa(vars->moves);
	mlx_string_put(vars->mlx, vars->window, 10, 10, 43905, moves);
	free(moves);
	return (0);
}
