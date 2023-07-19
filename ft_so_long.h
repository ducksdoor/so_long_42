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

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_vars
{
	void			*mlx;
	void			*window;
	void			*floor;
	void			*box;
	void			*door;
	void			*door2;
	struct s_player	*player;
	int				nx;
	int				ny;
	struct s_eat	*teat;
	char			*aux;
	char			**map;
	char			**foo;
	char			*file;
	int				moves;
}				t_vars;

typedef struct s_player
{
	void	*img;
	int		x;
	int		y;
}				t_player;

typedef struct s_eat
{
	void	*img;
	int		rest;
}				t_eat;

int		ft_close(t_vars *vars);
char	*ft_readmap(t_vars *vars);
void	ft_inition1(t_vars *vars);
int		render(t_vars *vars);
void	ft_middle_render(t_vars *vars, char **map, int i, int j);
void	ft_finish_render(t_vars *vars, int i, int j);
int		left(t_vars *vars);
int		right(t_vars *vars);
int		moveup(t_vars *vars);
int		movedown(t_vars *vars);
void	ft_error(t_vars *vars);
void	ft_errormap(t_vars *vars);
void	ft_failchar(t_vars *vars);
void	ft_segurity(t_vars *vars);
void	ft_goodmap(t_vars *vars);
void	ft_full(t_vars *vars, int y, int x);
void	ft_img(t_vars *vars);
void	ft_img2(t_vars *vars);
void	ft_ber(t_vars *vars, char *av);
void	ft_finish(t_vars *vars);
void	ft_print_error(char *str);
#endif
