/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:14:43 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/24 15:15:06 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearr(void **str)
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
