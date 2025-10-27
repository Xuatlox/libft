/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:41:12 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/27 17:58:48 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_parts(char const *s, char const c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static const char	*find_part(char const *s, const char c, int ref)
{
	int		i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (ref > 0)
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		ref--;
	}
	return (&s[i]);
}

static void	fill_part(char *res, char const *part, int const size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		res[i] = part[i];
		i++;
	}
	res[i] = 0;
}

static char	**desalloc(char **res, int const size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	*part;
	char	**res;
	int		nb_parts;

	i = 0;
	nb_parts = count_parts(s, c);
	if (!s)
		return (NULL);
	res = ft_calloc(nb_parts + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (i < nb_parts)
	{
		j = 0;
		part = (char *) find_part(s, c, i);
		res[i] = malloc(j + 1);
		if (!res[i])
			return (desalloc(res, i));
		fill_part(res[i], part, j);
		i++;
	}
	return (res);
}
