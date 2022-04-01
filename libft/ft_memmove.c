/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:11:09 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 14:11:11 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	size_t				i;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (!cdest && !csrc)
		return (NULL);
	if (csrc < cdest)
	{
		while (++i <= n)
			cdest[n - i] = csrc[n - i];
	}
	else
		while (n-- > 0)
			*(cdest++) = *(csrc++);
	return (dest);
}
