/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:40:21 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/09 10:47:15 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str)
	{
		ft_bzero(str[i], ft_strlen(str[i]));
		free(str[i]);
		i++;
	}
	return ;
}

static int	ft_fwords(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while ((s[i] == c) && (s[i]))
			i++;
		if ((s[i] != c) && (s[i]))
		{
			i++;
			j++;
			while ((s[i] != c) && (s[i]))
				i++;
		}
	}
	return (j);
}

static size_t	ft_fwordlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while ((s[i] != c) && (s[i]))
		i++;
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * ft_fwords(s, c) + 1);
	if (!new)
		return (NULL);
	while (i < ft_fwords(s, c))
	{
		while (s[j] == c)
			j++;
		new[i] = ft_strsub(&s[j], 0, ft_fwordlen(&s[j], c));
		if (!new[i])
		{
			ft_free(new);
			return (NULL);
		}
		j = j + ft_fwordlen(&s[j], c);
		i++;
	}
	new[i] = NULL;
	return (new);
}
