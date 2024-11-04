/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:47 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:38:53 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*uc_dest;
	const unsigned char	*uc_src;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	if (dest == NULL || src == NULL)
		return (NULL);
	uc_dest = (unsigned char *)dest;
	uc_src = (const unsigned char *)src;
	while (n-- > 0)
		*uc_dest++ = *uc_src++;
	return (dest);
}
