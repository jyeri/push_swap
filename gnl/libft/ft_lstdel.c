/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:44:46 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/16 16:44:48 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	current = *alst;
	while (current)
	{
		del(current->content, current->content_size);
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*alst = (NULL);
}
