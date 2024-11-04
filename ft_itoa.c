/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:49:43 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:37:54 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long n)
{
	int		len;
	long	long_num;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	if (n < 0)
		long_num = -(long)n;
	else
		long_num = (long)n;
	while (long_num > 0)
	{
		long_num /= 10;
		len++;
	}
	return (len);
}

static void	ft_setstr_from_int(char *str, int n, int len)
{
	long	long_num;

	if (n < 0)
	{
		str[0] = '-';
		long_num = -(long)n;
	}
	else
		long_num = (long)n;
	if (long_num == 0)
		str[--len] = '0';
	while (long_num > 0)
	{
		str[--len] = (long_num % 10) + '0';
		long_num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;

	len = ft_int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	ft_setstr_from_int(str, n, len);
	return (str);
}

