/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:38:33 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/12/14 21:21:11 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getstring(char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*expand(va_list p_arg, const char next)
{
	char	*expanded;

	if (next == 'i' || next == 'd')
		expanded = ft_itoa(va_arg(p_arg, int));
	else if (next == 's')
		expanded = ft_getstring(va_arg(p_arg, char *));
	else if (next == 'c')
		expanded = ft_getchar(va_arg(p_arg, int));
	else if (next == 'p')
		expanded = ft_getpointer(va_arg(p_arg, uintptr_t), HEX_LOWER);
	else if (next == 'u')
		expanded = ft_utoa_base(va_arg(p_arg, unsigned int), DEC_LOWER);
	else if (next == 'x')
		expanded = ft_utoa_base(va_arg(p_arg, unsigned int), HEX_LOWER);
	else if (next == 'X')
		expanded = ft_utoa_base(va_arg(p_arg, unsigned int), HEX_UPPER);
	else if (next == '%')
		expanded = ft_strdup("%");
	else
		expanded = ft_strdup("");
	if (expanded == NULL)
		return (NULL);
	return (expanded);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list		p_arg;
	t_output	output;

	if (format == NULL || fd < 0)
		return (ERROR_NUM);
	va_start(p_arg, format);
	output = initialize(format);
	if (output.string == NULL)
		return (va_end(p_arg), ERROR_NUM);
	if (format_output_string(&output, p_arg, format) == ERROR_NUM)
	{
		free(output.string);
		return (va_end(p_arg), ERROR_NUM);
	}
	if (write(fd, output.string, output.length) == ERROR_NUM)
	{
		free(output.string);
		return (va_end(p_arg), ERROR_NUM);
	}
	free(output.string);
	va_end(p_arg);
	return (output.length);
}
