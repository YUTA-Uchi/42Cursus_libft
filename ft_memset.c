/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:08:18 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:39:18 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*p;

	if (s == NULL)
		return (NULL);
	uc = (unsigned char) c;
	p = (unsigned char *) s;
	while (n > 0)
	{
		*p++ = uc;
		n--;
	}
	return (s);
}
