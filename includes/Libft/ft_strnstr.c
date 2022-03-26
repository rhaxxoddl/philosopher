/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:41:02 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 14:19:33 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*src == 0)
		return ((char *)dest);
	while (dest[i] && i < len)
	{
		j = 0;
		while (dest[i + j] == src[j] && i + j < len)
		{
			if (src[j + 1] == 0)
				return ((char *)(dest + i));
			j++;
		}
		i++;
	}
	return (0);
}
