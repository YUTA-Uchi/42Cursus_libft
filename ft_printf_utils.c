/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:29:10 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/12/10 19:32:37 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getchar(int c)
{
	char	*char_str;

	char_str = (char *)malloc(sizeof(char) * 2);
	if (char_str == NULL)
		return (NULL);
	char_str[0] = c;
	char_str[1] = '\0';
	return (char_str);
}

size_t	count_pointer_digits(uintptr_t n, unsigned int num_base)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= num_base;
		len++;
	}
	return (len);
}

char	*ft_getpointer(uintptr_t n, char *base)
{
	char			*str_num;
	size_t			digits;
	unsigned int	num_base;

	if (n == 0)
		return (ft_strdup("(nil)"));
	if (base == NULL || ft_strlen(base) < 2)
		return (NULL);
	digits = 0;
	num_base = ft_strlen(base);
	digits = count_pointer_digits(n, num_base) + 2;
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (str_num == NULL)
		return (NULL);
	str_num[digits] = '\0';
	while (n > 0)
	{
		str_num[--digits] = base[n % num_base];
		n /= num_base;
	}
	str_num[--digits] = 'x';
	str_num[--digits] = '0';
	return (str_num);
}

size_t	count_digits(unsigned int n, unsigned int num_base)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= num_base;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char			*str_num;
	size_t			digits;
	unsigned int	num_base;

	if (n == 0)
		return (ft_strdup("0"));
	if (base == NULL || ft_strlen(base) < 2)
		return (NULL);
	digits = 0;
	num_base = ft_strlen(base);
	digits = count_digits(n, num_base);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (str_num == NULL)
		return (NULL);
	str_num[digits] = '\0';
	while (n > 0)
	{
		str_num[--digits] = base[n % num_base];
		n /= num_base;
	}
	return (str_num);
}
