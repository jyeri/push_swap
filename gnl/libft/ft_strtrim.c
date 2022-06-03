/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:28:10 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/05 16:28:13 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	end = 0;
	start = 0;
	while (s[end] != '\0')
		end++;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n')
		end--;
	new = (char *)malloc(sizeof(char) * end - start + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (start < end)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
