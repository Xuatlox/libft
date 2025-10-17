/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:34:27 by ansimonn          #+#    #+#             */
/*   Updated: 2025/09/11 11:36:37 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_digits(char *digits, int *res)
{
	int		i;
	int		mul;
	char	res_tmp[10];

	i = 0;
	mul = 1;
	while (digits[i] >= '0' && digits[i] <= '9')
	{
		res_tmp[i] = digits[i];
		i++;
		mul *= 10;
	}
	mul /= 10;
	i = 0;
	while (res_tmp[i])
	{
		*res += mul * (res_tmp[i] - 48);
		i++;
		mul /= 10;
	}
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	sign = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			add_digits(&str[i], &res);
			return (sign * res);
		}
		i++;
	}
	return (0);
}
