/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:41:12 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/28 10:22:00 by ansimonn         ###   ########.fr       */
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

static const char	*find_part(char const *s, const char c, int ref, int *size)
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
	while (s[i + *size] && s[i + *size] != c)
	{
		(*size)++;
	}
	return (&s[i]);
}

static void	fill_part(char *res, char const *part, char c)
{
	int		i;

	i = 0;
	while (part[i] && part[i] != c)
	{
		res[i] = part[i];
		i++;
	}
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
	int		part_size;
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
		part_size = 0;
		part = (char *) find_part(s, c, i, &part_size);
		res[i] = ft_calloc( part_size + 1, sizeof(char));
		if (!res[i])
			return (desalloc(res, i));
		fill_part(res[i], part, c);
		i++;
	}
	return (res);
}
