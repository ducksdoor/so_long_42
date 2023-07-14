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

int	ft_close(int keycode, t_vars *vars)
{
	(void) keycode;
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

/* to do

	3 = SOLO puede aceptar .ber, quiza usar strrchr?




= SI el mapa que no existe que no salga segmentation 
= retocar el makefi?
= al acabar comprobar printf y ft_printf.  no puedemn existir printf

imagenes no correctas NO SEGMENTE???
	¿¿¿¿ BONUS?????


En caso de fallos el programa debe terminar correctamente y 
	devolver “Error\n” seguido de un mensajeexplícito de tu elección.
que el mapa sea rectangular
-- mitozorro
que este rodeado de muros
pasar la norminet
COMPROBAR PORQUE CIERRA TAN TARDE
evitar leaks
--invalid char
iniciar variables en ft especifica. 
tiene que tener al menos un coleccionable, una salida y un solo personaje
= ver si el camino es posible a todos los items
= solo puede abrir archivos .ber


	
 */