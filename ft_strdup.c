/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:23:07 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:08 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (len == SIZE_MAX)
		return (NULL);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memmove(ret, s, len + 1);
	return (ret);
}
