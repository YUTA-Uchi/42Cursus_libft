/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:26:09 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/10/31 20:15:15 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*point_of_big;
	const char	*point_of_little;
	size_t		tmp_len;

	if (big == NULL || little == NULL || !*little)
		return ((char *)big);
	while (len && *big)
	{
		point_of_big = big;
		point_of_little = little;
		tmp_len = len;
		while (tmp_len && *point_of_little
			&& *point_of_big == *point_of_little)
		{
			point_of_big++;
			point_of_little++;
			tmp_len--;
		}
		if (!*point_of_little)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
