/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:38:33 by yuuchiya          #+#    #+#             */
/*   Updated: 2025/03/26 15:22:43 by yuuchiya         ###   ########.fr       */
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

t_output	*initialize(const char *format)
{
	t_output	*output;
	size_t		format_len;

	format_len = ft_strlen(format);
	output = (t_output *)malloc(sizeof(t_output));
	if (output == NULL)
		return (NULL);
	output->string = (char *)malloc(sizeof(char) * (format_len + 1));
	if (output->string == NULL)
		return (free(output), NULL);
	output->len_alloc = format_len + 1;
	output->length = 0;
	return (output);
}

void	free_output(t_output *output)
{
	if (output == NULL)
		return ;
	free(output->string);
	free(output);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list		p_arg;
	t_output	*output;
	size_t		len;

	if (format == NULL || fd < 0)
		return (ERROR_NUM);
	va_start(p_arg, format);
	output = initialize(format);
	if (!output)
		return (va_end(p_arg), ERROR_NUM);
	if (format_output_string(output, p_arg, format) == ERROR_NUM)
	{
		free_output(output);
		return (va_end(p_arg), ERROR_NUM);
	}
	if (write(fd, output->string, output->length) == ERROR_NUM)
	{
		free_output(output);
		return (va_end(p_arg), ERROR_NUM);
	}
	len = output->length;
	free_output(output);
	va_end(p_arg);
	return (len);
}
