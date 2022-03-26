/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:34:24 by sanjeon           #+#    #+#             */
/*   Updated: 2021/10/25 14:25:04 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	array_size(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**free_split(char **output, size_t i)
{
	size_t	idx;

	idx = 0;
	while (idx < i)
		free(output[idx++]);
	free(output);
	return (0);
}

char	**array_split(char const *s, char c, char **output)
{
	size_t	count;
	size_t	i;
	size_t	output_i;

	output_i = 0;
	i = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] == c)
			i++;
		if (!s[i])
			return (output);
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		output[output_i] = ft_substr(s, i - count, count);
		if (output[output_i] == 0)
			return (free_split(output, output_i));
		output_i++;
	}
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;

	if (s == 0)
		return (0);
	output = (char **)ft_calloc(array_size(s, c) + 1, sizeof(char *));
	if (output == 0)
		return (0);
	output = array_split(s, c, output);
	return (output);
}
