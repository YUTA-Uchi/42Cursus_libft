/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:10:22 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/10/30 14:57:29 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	index;
	size_t	src_len;

	if (dest == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	index = 0;
	if (dsize != 0)
	{
		while (src[index] != '\0' && index < dsize -1)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (src_len);
}
