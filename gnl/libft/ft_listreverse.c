/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:17:30 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/18 16:17:33 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listreverse(t_list **alst)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	next = NULL;
	current = *alst;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*alst = prev;
}
