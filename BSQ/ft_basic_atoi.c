/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:53:33 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:53:38 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_basic_atoi(char *fl, int size)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (fl[i] >= '0' && fl[i] <= '9' && i < size)
	{
		nbr = (nbr * 10) + (fl[i] - '0');
		i++;
	}
	if (i == 0)
	{
		return (-1);
	}
	return (nbr);
}
