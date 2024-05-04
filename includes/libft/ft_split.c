/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:20:13 by codespace         #+#    #+#             */
/*   Updated: 2024/04/19 20:47:23 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	nextline(char **newstr, size_t *newstrlen, char c)
{
	size_t	i;

	*newstr += *newstrlen;
	*newstrlen = 0;
	i = 0;
	while (**newstr && **newstr == c)
		(*newstr)++;
	while ((*newstr)[i])
	{
		if ((*newstr)[i] == c)
			return ;
		(*newstrlen)++;
		i++;
	}
}

static char	**freemal(char **tabelle)
{
	size_t	i;

	i = 0;
	while (tabelle[i])
	{
		free(tabelle[i]);
		i++;
	}
	free(tabelle);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**next;
	char	*str;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	next = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!next)
		return (NULL);
	i = 0;
	str = (char *)s;
	len = 0;
	while (i < wordcount(s, c))
	{
		nextline(&str, &len, c);
		next[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!next[i])
			return (freemal(next));
		ft_strlcpy(next[i], str, len + 1);
		i++;
	}
	next[i] = NULL;
	return (next);
}

/*#include <stdio.h>

int	main(void)
{
	const char	*s;
	char		c;

	s = "check-this";
	c = '-';

	for (int i = 0; i < 3; i++)
		printf("%s\n", 	ft_split(s, c)[i]);
}

 the if check for previous char in wordcount is for last array*/