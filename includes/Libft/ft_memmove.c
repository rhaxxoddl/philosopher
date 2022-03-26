/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 01:15:41 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 14:18:22 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	temp;
	unsigned int	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (src >= dest)
	{
		while (i < n)
		{
			temp = ((unsigned char *)src)[i];
			((unsigned char *)dest)[i++] = temp;
		}
	}
	else
	{
		while (n)
		{
			temp = ((unsigned char *)src)[n - 1];
			((unsigned char *)dest)[n - 1] = temp;
			n--;
		}
	}
	return (dest);
}
