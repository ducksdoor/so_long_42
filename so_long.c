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

int	key_hook(int keycode, t_vars *vars)
{
	int			aux;

	aux = 2;
	if (keycode == 53)
		ft_close(keycode, vars);
	if (keycode == 0 || keycode == 123)
		aux = left(vars);
	else if (keycode == 2 || keycode == 124)
		aux = right(vars);
	else if (keycode == 13 || keycode == 126)
		aux = moveup(vars);
	else if (keycode == 1 || keycode == 125)
		aux = movedown(vars);
	if (aux == 0)
	{
		vars->moves++;
		ft_printf("llevas %d mov:\n", vars->moves);
		render (vars);
	}
	ft_finish(vars);
	return (0);
}
void	leaks(void)
{
	system("leaks -q so_long");
} 



int	main(int ac, char *av[])
{
	t_vars		*vars;

	if (ac != 2 && av)
		ft_print_error("No existe segundo argumento");
	// atexit(leaks);

	vars = malloc(sizeof(t_vars));
	ft_ber(vars, av[1]);
	if (vars == NULL)
		exit (1);
	ft_inition1(vars);
	ft_error(vars);
	ft_errormap(vars);
	ft_failchar(vars);
	ft_goodmap(vars);
	vars->window = mlx_new_window(vars->mlx,
			vars->nx * 64, vars->ny * 64, "so_long");
	render(vars);
	mlx_key_hook(vars->window, key_hook, vars);
	mlx_hook(vars->window, 17, (1L << 17), ft_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}
