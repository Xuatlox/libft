/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:40:51 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/21 17:52:59 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static void	fill_res(char *res, int n)
{
	int		i;
	int		neg;

	i = get_size(n) - 1;
	res[get_size(n)] = 0;
	neg = 0;
	if (n < 0)
	{
		res[0] = '-';
		neg = 1;
		n = -n;
	}
	while (i >= neg)
	{
		res[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc(get_size(n) + 1);
	if (!res)
		return (NULL);
	fill_res(res, n);
	return (res);
}
