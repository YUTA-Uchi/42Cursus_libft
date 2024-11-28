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
	char	*ret_for_set;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (len == SIZE_MAX)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret_for_set = ret;
	while (*s)
		*ret_for_set++ = *s++;
	return (ret);
}
