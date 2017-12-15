/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:22:10 by mdamesto          #+#    #+#             */
/*   Updated: 2015/11/30 20:20:50 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	content_size = 0;
	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
		tmp->content = NULL;
	else
		tmp->content = (void *)content;
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
