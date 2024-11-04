/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:11:54 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:39:01 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (dest == NULL || src == NULL)
		return (NULL);
	p_dest = (char *)dest;
	p_src = (const char *)src;
	if (p_dest == p_src || n == 0)
		return (dest);
	else if (p_dest < p_src)
	{
		while (n-- > 0)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += n - 1;
		p_src += n - 1;
		while (n-- > 0)
			*p_dest-- = *p_src--;
	}
	return (dest);
}
