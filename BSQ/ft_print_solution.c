/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:55:05 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:55:10 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void		ft_print_map(int **arr, t_fline *fline, int row_len)
{
	int i;
	int j;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		while (j < row_len)
		{
			if (arr[i][j] == 0)
				write(1, &fline->obstacle, 1);
			if (arr[i][j] == 7)
				write(1, &fline->full, 1);
			if (arr[i][j] == 1)
				write(1, &fline->empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void		ft_print_solution(int **arr, int *sol, int row_len, t_fline *fline)
{
	int size;
	int i;
	int j;

	size = sol[2];
	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		size = sol[2];
		while (j < row_len)
		{
			if (arr[i][j] != 0 && !(i == sol[0] && j == sol[1]))
				arr[i][j] = 1;
			if (sol[0] - size < i && i <= sol[0] &&
				sol[1] - size < j && j <= sol[1])
				arr[i][j] = 7;
			j++;
		}
		i++;
	}
	free(sol);
	ft_print_map(arr, fline, row_len);
}
