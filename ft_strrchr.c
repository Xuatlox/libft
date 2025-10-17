/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:59:30 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/16 18:20:41 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (c % 256 == 0)
		return (((char *)s) + i + 1);
	while (i >= 0)
	{
		if (s[i] == c % 256)
			return (((char *)s) + i);
		i--;
	}
	return (0);
}
