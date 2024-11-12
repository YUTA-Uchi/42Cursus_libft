/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:11:54 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/12 21:56:02 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	if (dest < src && n > 0)
	{
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(const unsigned char *)(src + i);
			i++;
		}
	}
	else if (dest > src && n > 0)
	{
		i = n - 1;
		while (i > 0)
		{
			*(unsigned char *)(dest + i) = *(const unsigned char *)(src + i);
			i--;
		}
		*(unsigned char *)(dest + i) = *(const unsigned char *)(src + i);
	}
	return (dest);
}
