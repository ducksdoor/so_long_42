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


void	ft_img2(t_vars *vars)
{
	int		ancho;
	int		alto;
	char	*rute;

	rute = ft_strdup("./img/box.xpm");
	vars->box = mlx_xpm_file_to_image(vars->mlx, rute, &ancho, &alto);
	free(rute);
	rute = ft_strdup("./img/close.xpm");
	vars->door = mlx_xpm_file_to_image(vars->mlx, rute, &ancho, &alto);
	free(rute);
	rute = ft_strdup("./img/open.xpm");
	vars->door2 = mlx_xpm_file_to_image(vars->mlx, rute, &ancho, &alto);
	free(rute);
	if (!vars->box || !vars->door || !vars->door2)
	{
		ft_print_error("Hay una imagen que no existe");
		exit(1);
	}
}

void	ft_img(t_vars *vars)
{
	int		ancho;
	int		alto;
	char	*rute;

	rute = ft_strdup("./img/steak.xpm");
	vars->teat->img = mlx_xpm_file_to_image(vars->mlx, rute, &ancho, &alto);
	free(rute);
	rute = ft_strdup("./img/floor.xpm");
	vars->floor = mlx_xpm_file_to_image(vars->mlx, rute, &ancho, &alto);
	free(rute);
	rute = ft_strdup("./img/fox.xpm");
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, rute, &ancho, &alto);
	free(rute);
	if (!vars->teat->img || !vars->floor || !vars->player->img)
	{
		ft_print_error("Hay una imagen que no existe");
		exit(1);
	}
	ft_img2(vars);
}
