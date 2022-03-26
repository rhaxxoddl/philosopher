/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:19:18 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 14:20:05 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	s_len;
	size_t	i;

	temp = (char *)ft_calloc(len + 1, sizeof(char));
	if (temp == 0 || s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (temp);
	i = 0;
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[len] = 0;
	return (temp);
}
