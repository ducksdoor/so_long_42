/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:58:28 by lortega-          #+#    #+#             */
/*   Updated: 2023/04/06 13:06:57 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*next_word(char const **s, char c)
{
	char	*start;
	char	*end;
	char	*word;

	while (**s && **s == c)
		(*s)++;
	start = (char *)*s;
	while (**s && **s != c)
		(*s)++;
	end = (char *)*s;
	word = ft_substr(start, 0, end - start);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**words;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		words[i] = next_word(&s, c);
		if (!words[i])
		{
			while (i-- > 0)
				free(words[i]);
			free(words);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
/*
#include <stdio.h>

int main (void)
{
	char *a = "  esto  me da dolor de cabeza ... huhuh "; 
	char c = ' ';
	char	p; 
	int	x = 0;	
	char **r = ft_split("hhello!", ' ');
	p = count_words(a, c);	
	while (r[x])
	{	
		printf("%s\n%p\n", r[x], r[x]);
		x++;
	}
		printf("%s\n%p\n", r[x], r[x]);
}*/
