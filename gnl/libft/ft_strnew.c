/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:37:22 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/04 12:37:24 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	ft_bzero(new, (sizeof(char) * size + 1));
	return (new);
}
