/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:17:35 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:54:17 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_fl_size(char *fullmap)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (!fullmap)
		return (0);
	while (fullmap[i] != '\0' && fullmap[i] != '\n')
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_fl_copy(char *fullmap, int size)
{
	char	*fl;
	int		i;

	i = 0;
	fl = malloc(size + 1);
	if (!fl)
		return (0);
	if (!fullmap || size == 0)
	{
		free(fl);
		return (0);
	}
	while (fullmap[i] != '\0' && fullmap[i] != '\n')
	{
		fl[i] = fullmap[i];
		i++;
	}
	fl[size] = '\0';
	return (fl);
}

int		ft_first_line(char *fullmap, int fline_size, t_fline *fline)
{
	char	*fl;

	fl = ft_fl_copy(fullmap, fline_size);
	if (!fl)
		return (0);
	if (fline_size < 4)
	{
		free(fl);
		return (0);
	}
	fline->full = fl[--fline_size];
	fline->obstacle = fl[--fline_size];
	fline->empty = fl[--fline_size];
	fline->nbr_lines = ft_basic_atoi(fl, fline_size);
	free(fl);
	if (fline->nbr_lines < 1)
	{
		return (0);
	}
	return (1);
}
