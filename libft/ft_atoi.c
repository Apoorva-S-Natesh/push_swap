/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:14:56 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 15:25:57 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n')
		return (1);
	if (str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *string)
{
	long	res;
	long	sign;

	while (ft_isspace(*string))
		string++;
	sign = 1;
	if (*string == '-' || *string == '+')
		if (*(string++) == '-')
			sign = -1;
	res = 0;
	while (*string && ft_isdigit(*string))
	{
		res = 10 * res + *string - '0';
		if (res * sign > 2147483647L)
			return (-1);
		else if (res * sign < -2147483648L)
			return (0);
		string++;
	}
	return ((int)(res * sign));
}
