/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 15:49:07 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 14:19:53 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_len;
	size_t	back_len;
	char	*trim;
	size_t	s_len;

	if (!s1 || !set)
		return (0);
	s_len = ft_strlen(s1);
	front_len = 0;
	while (ft_strchr(set, s1[front_len]) && front_len < s_len)
		front_len++;
	if (front_len == s_len)
		return (trim = ft_calloc(1, sizeof(char)));
	back_len = 0;
	while (ft_strchr(set, s1[s_len - back_len - 1]) && back_len < s_len)
		back_len++;
	trim = ft_substr(s1, front_len, s_len - front_len - back_len);
	return (trim);
}
