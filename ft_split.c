/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:23:26 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/03 16:40:44 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_data_array(char **data, size_t index)
{
	while (index > 0)
	{
		index--;
		if (data[index])
			free(data[index]);
	}
	free(data);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_findword(char const **s, char c)
{
	size_t		str_index;

	str_index = 0;
	while (**s && **s == c)
		(*s)++;
	while (**s && **s != c)
	{
		str_index++;
		(*s)++;
	}
	return (ft_substr(*s - str_index, 0, str_index));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	result_index;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	if (words == SIZE_MAX)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	result_index = 0;
	while (words--)
	{
		result[result_index] = ft_findword(&s, c);
		if (result[result_index] == NULL)
		{
			free_data_array(result, result_index);
			return (NULL);
		}
		result_index++;
	}
	result[result_index] = NULL;
	return (result);
}
