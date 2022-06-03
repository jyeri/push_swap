/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:11:33 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 13:11:35 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strcmp(haystack, needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (!(ft_memcmp(haystack, needle, ft_strlen(needle))))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
