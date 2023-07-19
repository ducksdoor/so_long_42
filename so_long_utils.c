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

int	ft_close(t_vars *vars)
{
	if (!vars)
		exit(1);
	exit(1);
}

char	*ft_readmap(t_vars *vars)
{
	int		fd;
	char	*buffer;
	char	*line;
	int		x;

	buffer = NULL;
	x = 0;
	fd = open(vars->file, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("No se puede abrir el mapa");
		exit(1);
	}
	while (1 && vars)
	{
		if (!buffer)
			buffer = ft_calloc(sizeof(char), 1);
		line = ft_get_next_line(fd);
		if (line == NULL)
			return (buffer);
		buffer = ft_strjoin(buffer, line);
		free(line);
	}
	close(fd);
	return (buffer);
}

void	ft_contx(t_vars *vars)
{
	int		fd;
	char	*aux;
	int		contx;

	fd = open(vars->file, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("No se puede abrir el mapa");
		exit(1);
	}
	aux = ft_get_next_line(fd);
	close(fd);
	contx = ft_strlen(aux) - 1;
	free(aux);
	vars->nx = contx;
	return ;
}

void	ft_conty(t_vars *vars)
{
	int		fd;
	char	*aux;
	int		conty;

	conty = 0;
	fd = open(vars->file, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error("No se puede abrir el mapa");
		exit(1);
	}
	while (1)
	{
		aux = ft_get_next_line(fd);
		if (aux == NULL)
			break ;
		conty++;
		free(aux);
	}
	close(fd);
	vars->ny = conty;
	return ;
}

void	ft_inition1(t_vars *vars)
{
	int	x;

	x = 0;
	vars->aux = ft_readmap(vars);
	ft_segurity(vars);
	vars->teat = malloc(sizeof(t_eat));
	vars->player = malloc(sizeof(t_player));
	vars->teat->rest = 0;
	vars->player->x = 0;
	vars->player->y = 0;
	while (vars->aux[x] != '\0')
	{
		if (vars->aux[x] == 'C')
			vars->teat->rest++;
		x++;
	}
	vars->moves = 0;
	vars->mlx = mlx_init();
	vars->map = ft_split(vars->aux, '\n');
	vars->foo = ft_split(vars->aux, '\n');
	ft_img(vars);
	ft_contx(vars);
	ft_conty(vars);
}
