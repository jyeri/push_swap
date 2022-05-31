/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:53:00 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:18:17 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "checker.h"

int	ft_atoi_w_intlimit(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
	{
		ft_putstr ("Error\n");
		exit(-1);
	}
	return (res * sign);
}

int	int_len(int nm)
{
	int	i;
	int	len;

	len = 0;
	i = nm;
	if (i < 0)
	{
		i = i * -1;
		len++;
	}
	while (i > 0)
	{
		len++;
		i = i / 10;
	}
	return (len);
}

int	ft_digitss(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			i++;
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (1);
	}
	return (0);
}
