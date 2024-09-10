/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isai.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:46:41 by asomanah          #+#    #+#             */
/*   Updated: 2024/08/12 13:11:15 by asomanah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isai(const char *string)
{
	if (*string == '-' || *string == '+')
		string++;
	if (!*string)
		return (0);
	while (*string)
	{
		if (*string < '0' || *string > '9')
			return (0);
		string++;
	}
	return (1);
}
