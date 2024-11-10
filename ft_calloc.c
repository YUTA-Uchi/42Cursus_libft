/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:13:19 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/03 16:48:14 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**  
 * 1.preprocess(for args=0)
 * 	 return unique pointer value
 * 2.null guard(for overflow)
 *   detect integer(abstract. not int etc.) overflow
 * 3.allocate
 * 4.set the allocated obj to 0
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	return (ft_bzero(res, nmemb * size));
}
