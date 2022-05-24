/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:06:20 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 13:06:23 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int x)
{
	if ((x > 64 && x < 91) || (x > 96 && x < 123))
		return (1);
	else
		return (0);
}