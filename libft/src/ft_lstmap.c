/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:03:18 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/30 13:20:11 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *r;
	t_list *new;

	if (f == NULL || lst == NULL)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	r = new;
	while (lst)
	{
		new->next = f(lst);
		lst = lst->next;
		new = new->next;
	}
	return (r);
}
