/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:07:55 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/08 12:07:58 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			i;
	long int	c;

	c = n;
	i = 0;
	len = ft_nblen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (c < 0)
	{
		str[i++] = '-';
		c = c * -1;
	}
	if (c == 0)
		str[i++] = '0';
	str[len--] = '\0';
	while (c)
	{
		str[len--] = c % 10 + '0';
		c = c / 10;
	}
	return (str);
}
