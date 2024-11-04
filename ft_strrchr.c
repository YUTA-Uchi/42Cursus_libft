/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:13:32 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/02 15:30:42 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*ret;

	uc = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	ret = NULL;
	while (*s)
	{
		if (*s == uc)
			ret = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (ret);
}
