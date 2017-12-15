/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:38:10 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/28 19:14:48 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp2;

	tmp2 = malloc(sizeof(t_list));
	tmp = *alst;
	tmp2->next = tmp->content;
	while (*alst)
	{
		tmp = *alst;
		tmp2 = tmp->next;
		ft_lstdelone(alst, del);
		*alst = tmp2;
	}
}
