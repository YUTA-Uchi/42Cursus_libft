/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:48:28 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/04 12:39:39 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_int_recursive(unsigned int num, int fd)
{
	if (num >= 10)
		put_int_recursive(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	put_int_recursive(num, fd);
}
