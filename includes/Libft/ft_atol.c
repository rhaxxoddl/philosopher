/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:09:41 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 16:46:27 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	char		*str;
	long long	num;

	i = 0;
	str = (char *)nptr;
	num = 0;
	sign = -1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
		num = num * 10 - str[i++] + '0';
	return (sign * num);
}
