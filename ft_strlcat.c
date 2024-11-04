/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:20:15 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:31 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (s[len] && len < n)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	max_cat;

	if (dest == NULL || src == NULL)
		return (0);
	dest_len = ft_strnlen(dest, size);
	src_len = ft_strlen(src);
	if (size == 0 || dest_len >= size)
		return (size + src_len);
	max_cat = size - dest_len - 1;
	dest += dest_len;
	while (*src && max_cat > 0)
	{
		*dest++ = *src++;
		max_cat--;
	}
	*dest = '\0';
	return (dest_len + src_len);
}
