/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:54:52 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:54:56 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_row_len(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

int		**ft_fill_arr(int **arr, char empty, int row_len)
{
	int i;
	int j;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		while (j < row_len)
		{
			if (arr[i][j] == empty)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

int		**ft_map_to_arr(char *map, int nbr_lines, char empty)
{
	int row_len;
	int **arr;
	int i;
	int j;
	int	column;

	row_len = ft_row_len(map);
	if (!(arr = malloc(sizeof(int*) * ((nbr_lines) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i < nbr_lines)
	{
		if (!(arr[i] = malloc(sizeof(int) * row_len)))
			return (0);
		column = 0;
		while (map[j] != '\n')
			arr[i][column++] = map[j++];
		j++;
		i++;
	}
	arr[i] = 0;
	arr = ft_find_solution(ft_fill_arr(arr, empty, row_len), row_len);
	return (arr);
}
