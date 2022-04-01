/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:29:37 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/05 15:29:39 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	int		j;
	int		len;
	char	*new;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1);
	j = ft_strlen(s2);
	len = 0;
	new = (char *)malloc((sizeof(char) * x + j) + 1);
	if (!new)
		return (NULL);
	while (x > len)
		new[i++] = s1[len++];
	len = 0;
	while (j > len)
		new[i++] = s2[len++];
	new[i] = '\0';
	return (new);
}
