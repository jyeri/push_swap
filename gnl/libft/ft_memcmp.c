/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:25:02 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 15:25:04 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*xs1;
	unsigned char	*xs2;

	xs1 = (unsigned char *)s1;
	xs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*xs1 != *xs2)
			return (*xs1 - *xs2);
		n--;
		xs1++;
		xs2++;
	}
	return (0);
}
