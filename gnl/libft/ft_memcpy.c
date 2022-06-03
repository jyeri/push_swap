/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:44:36 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 13:44:40 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*cdest;
	char			*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
