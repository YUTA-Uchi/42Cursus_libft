/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:25:27 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/03 16:09:49 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	result = ft_strdup(s);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (result[index])
	{
		result[index] = f(index, result[index]);
		index++;
	}
	return (result);
}
