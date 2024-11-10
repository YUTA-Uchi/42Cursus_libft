/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:48:10 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:36:41 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}
/**
 * 1.skip space(isspace(3))
 * 2.detect sign once
 * 3.convert first digit part of str
 */
int	ft_atoi(const char *str)
{
	int	result_num;
	int	result_sign;

	result_num = 0;
	result_sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			result_sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result_num > (INT_MAX - (*str - '0')) / 10)
		{
			if (result_sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result_num = result_num * 10 + (*str++ - '0');
	}
	return (result_sign * result_num);
}
