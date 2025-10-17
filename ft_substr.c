/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:32:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/17 16:15:11 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	i = 0;
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
