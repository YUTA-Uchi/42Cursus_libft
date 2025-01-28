/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:12:21 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/12/17 19:41:17 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*reallocate(t_output *output)
{
	char	*realloced;
	size_t	i;

	output->len_alloc *= 2;
	realloced = (char *)malloc(sizeof(char) * output->len_alloc);
	if (realloced == NULL)
		return (NULL);
	i = 0;
	while (i < output->length)
	{
		realloced[i] = output->string[i];
		i++;
	}
	return (realloced);
}

static int	append_char(t_output *output, char c)
{
	char	*realloced;

	if (output->string == NULL)
		return (ERROR_NUM);
	if (output->length + 1 >= output->len_alloc)
	{
		realloced = (char *)reallocate(output);
		free(output->string);
		output->string = realloced;
		if (output->string == NULL)
			return (ERROR_NUM);
	}
	output->string[output->length++] = c;
	return (SUCCESS_NUM);
}

static int	append_string(t_output *output, const char *str, const char next)
{
	size_t	i;
	char	*realloced;

	if (str == NULL || output->string == NULL)
		return (ERROR_NUM);
	if (next == 'c' && str[0] == '\0')
		return (append_char(output, '\0'));
	i = 0;
	while (str[i])
	{
		if (output->length + 1 >= output->len_alloc)
		{
			realloced = (char *)reallocate(output);
			free(output->string);
			output->string = realloced;
			if (output->string == NULL)
				return (ERROR_NUM);
		}
		output->string[output->length++] = str[i++];
	}
	return (SUCCESS_NUM);
}

int	format_output_string(t_output *output, va_list p_arg, const char *format)
{
	char	*expanded;
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			expanded = expand(p_arg, format[++i]);
			if (append_string(output, expanded, format[i]) == ERROR_NUM)
				return (free(expanded), ERROR_NUM);
			free(expanded);
			if (format[i] != '\0')
				i++;
		}
		else
		{
			if (append_char(output, format[i++]) == ERROR_NUM)
				return (ERROR_NUM);
		}
	}
	output->string[output->length] = '\0';
	return (SUCCESS_NUM);
}

t_output	initialize(const char *format)
{
	t_output	output;
	size_t		format_len;

	format_len = ft_strlen(format);
	output.string = (char *)malloc(sizeof(char) * (format_len + 1));
	if (output.string == NULL)
		return ((t_output){NULL, 0, 0});
	output.len_alloc = format_len + 1;
	output.length = 0;
	return (output);
}
