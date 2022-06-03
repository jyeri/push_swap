/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:13:23 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/15 13:13:26 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	node->content = malloc(content_size);
	if (!node->content)
		return (0);
	ft_memmove(node->content, content, content_size);
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
