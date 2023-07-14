https://aurelienbrabant-fr.translate.goog/blog/getting-started-with-the-minilibx?_x_tr_sl=en&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=sc&_x_tr_hist=true






Este es el comando.


cc -lmlx -framework OpenGL -framework AppKit so_lerick.c so_long_utils.c libft/libft.a




aqwui esta la antoigua funcion exit por siacaso

int	ft_close(int keycode, t_vars *vars)
{

	(void) keycode;
	if (!vars)
		exit(1);
	// while (vars->map[i])
	// 	free(vars->map[i++]);
	// free(vars->map);
	// free(vars->aux);
	// free(vars->player);
	// free(vars->teat);
	// free (vars);
	exit(1);
}



esto es para el bonus 1 

int	key_hook(int keycode, t_vars *vars)
{
	static int	move;
	int			aux;

	aux = 0;
	if (!move)
		move = 0;
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
		move++;
		vars->moves++;
	ft_printf("llevas %d mov:\n", move);
	ESTO ES EL BONUS//mlx_string_put(vars->mlx, vars->window, 10, 10, 43905, ft_itoa(move));
	return (0);
}
int	render(t_vars *vars)
{

 	int	i;
	int	j;
	char **map;
/* 	char *str_move; */
	
/* 	str_move = ft_itoa(vars->moves); */
	j = 0;
	map = vars->map;
	while(map[j])
	{
		i = 0;
		while(map[j][i])
		{
            ft_middle_render(vars, map, i, j);
			if (map[j][i] == 'n')
			{
				mlx_put_image_to_window(vars->mlx, vars->window, vars->door, i * 64, j * 64);
				mlx_put_image_to_window(vars->mlx, vars->window, vars->player->img, i * 64, j * 64);
				vars->player->x = i;
				vars->player->y = j;
			}
			i++;
		}
		j++;
	}
/* 	mlx_string_put(vars->mlx, vars->window, 10, 10, 43905, str_move);
	free(str_move); */
	return(0); 
}

-------------------





ESTO ES PARA VER LEAKS 

/* void	leaks(void)
{
	system("leaks -q so_long");
} */

EN EL MAINB HAY QUE PONER... 

//	atexit(leaks);



