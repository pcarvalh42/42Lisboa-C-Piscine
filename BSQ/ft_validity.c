/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:56:09 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:56:13 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_is_valid_c(char c, char empty, char obstacle, char full)
{
	if (c == '\n')
		return (0);
	if (c == empty)
		return (0);
	if (c == obstacle)
		return (0);
	if (c == full)
		return (0);
	return (1);
}

int		ft_lines_are_valid(char *map, int nbr_lines)
{
	int i;
	int lines;

	i = 0;
	lines = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			lines++;
		i++;
	}
	if (lines != nbr_lines)
	{
		return (1);
	}
	i = 0;
	return (0);
}

int		ft_lines_len(char *map, int nbr_lines)
{
	int i;
	int j;
	int line_len;

	line_len = 0;
	while (map[line_len] != '\n')
	{
		line_len++;
	}
	i = 0;
	while (nbr_lines > 0)
	{
		j = 0;
		while (map[i] != '\n')
		{
			i++;
			j++;
		}
		if (j != line_len)
			return (1);
		i++;
		nbr_lines--;
	}
	return (0);
}

int		ft_repeats(t_fline *fline)
{
	if ((fline->empty == fline->obstacle) || (fline->empty == fline->full))
		return (1);
	if (fline->full == fline->obstacle)
		return (1);
	return (0);
}

int		ft_map_is_valid(char *map, t_fline *fline)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (ft_is_valid_c(map[i], fline->empty, fline->obstacle, fline->full)
			!= 0 || ft_is_printable(map[i]) != 0)
		{
			ft_map_error();
			return (1);
		}
		i++;
	}
	if (ft_lines_are_valid(map, fline->nbr_lines) != 0 ||
			ft_lines_len(map, fline->nbr_lines) != 0 || ft_repeats(fline) != 0)
	{
		ft_map_error();
		return (1);
	}
	ft_lines_len(map, fline->nbr_lines);
	return (0);
}
