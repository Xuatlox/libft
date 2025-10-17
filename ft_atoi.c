/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:34:27 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/17 14:33:03 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	add_digits(const char *digits, int *res)
{
	int		i;
	int		mul;
	char	res_tmp[10];

	i = 0;
	mul = 1;
	while (digits[i] >= '0' && digits[i] <= '9')
	{
		res_tmp[i] = digits[i];
		mul *= 10;
		if (i == 0)
			mul /= 10;
		i++;
	}
	i = 0;
	while (res_tmp[i])
	{
		*res += mul * (res_tmp[i] - 48);
		i++;
		mul /= 10;
	}
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while ((nptr[0] >= 9 && nptr[0] <= 13) || nptr[0] == 32)
		nptr++;
	if (nptr[0] == '-')
		sign = -1;
	if (nptr[0] == '+' || nptr[0] == '-')
		nptr++;
	while (nptr[0] == '0')
		nptr++;
	if (nptr[0] >= '0' && nptr[0] <= '9')
	{
		add_digits(&nptr[0], &res);
		return (sign * res);
	}
	return (0);
}
