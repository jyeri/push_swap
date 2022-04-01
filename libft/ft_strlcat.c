/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcatUNDONE.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:03:21 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 16:03:23 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	j;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (dst_len >= n)
		return (n + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < n - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dst_len + src_len);
}
