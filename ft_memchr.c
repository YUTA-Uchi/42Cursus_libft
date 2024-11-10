/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:09:56 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:38:35 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		needle;
	const unsigned char	*haystack;

	if (s == NULL)
		return (NULL);
	needle = (unsigned char)c;
	haystack = (const unsigned char *)s;
	while (n > 0)
	{
		if (*haystack == needle)
			return ((void *)haystack);
		haystack++;
		n--;
	}
	return ((void *) NULL);
}
