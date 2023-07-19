/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:31:51 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/14 17:32:09 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*restmex(char *textmex)
{
	size_t	len;
	int		y;
	char	*rest;

	len = 0;
	y = 0;
	while (textmex[y] && textmex[y] != '\n')
		y++;
	if (textmex[y] == '\0')
	{
		free (textmex);
		return (NULL);
	}
	len = ft_strlen(textmex);
	len = len - y;
	rest = ft_gnl_substr(textmex, (y + 1), len);
	free(textmex);
	return (rest);
}

static char	*line(char *textmex)
{
	int		x;
	char	*lectura;

	x = 0;
	if (!textmex)
		return (NULL);
	while (textmex[x] != '\n' && textmex[x] != '\0')
		x++;
	lectura = ft_gnl_substr(textmex, 0, x + 1);
	return (lectura);
}

static char	*ft_clean(char **rest, char **buffer)
{
	free(*rest);
	free(*buffer);
	*rest = NULL;
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	static char	*rest;
	char		*lectura;
	int			x;

	x = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!rest)
		rest = ft_calloc(1, sizeof(char));
	while (x != 0 && ft_gnl_strchr(rest, '\n') == 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (ft_clean(&rest, &buffer));
		buffer[x] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	if (!rest)
		return (NULL);
	free(buffer);
	lectura = line(rest);
	rest = restmex(rest);
	return (lectura);
}
