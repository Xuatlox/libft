/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:00:59 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/17 17:51:00 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;
	int		cg;

	i = -1;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (set[++i])
	{
		cg = end - start;
		if (ft_strchr(s1, set[i]) == &s1[start])
			start++;
		else if (ft_strrchr(s1, set[i]) == &s1[end])
			end--;
		if (start == end)
			break;
		if (end - start != cg)
			i = 0;
	}
	str = ft_calloc(end - start + 1, sizeof(char));
	ft_strlcat(str, &s1[start], end - start + 1);
	return (str);
}

int		main()
{
	printf("%s\n", ft_strtrim("  fo o ", " "));
}
