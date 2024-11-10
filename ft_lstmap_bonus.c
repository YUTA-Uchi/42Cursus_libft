/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuchiya <yuuchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:37:27 by yuuchiya          #+#    #+#             */
/*   Updated: 2024/11/03 18:37:35 by yuuchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * 1.null guard
 * 2.traverse the last node and set next to new
 * 	2.1.apply func(f) and create new node
 *  2.2.if fail to allocate, free using func(del)
 *  2.3.add newnode to new list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*current;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	current = lst;
	new_list = NULL;
	while (current != NULL)
	{
		new_node = ft_lstnew(f(current->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}
