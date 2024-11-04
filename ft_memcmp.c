/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:09:52 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:38:46 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		return (-(int)*(const unsigned char *)s2);
	else if (s2 == NULL)
		return ((int)*(const unsigned char *)s1);
	uc1 = (const unsigned char *)s1;
	uc2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*uc1 != *uc2)
			return (*uc1 - *uc2);
		uc1++;
		uc2++;
		n--;
	}
	return (0);
}
