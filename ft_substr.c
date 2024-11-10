/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:02:23 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:41:07 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	subs_len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		ret = (char *)malloc(sizeof(char));
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (s_len - start < len)
		subs_len = s_len - start;
	else
		subs_len = len;
	if (subs_len == SIZE_MAX)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (subs_len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, subs_len + 1);
	return (ret);
}
