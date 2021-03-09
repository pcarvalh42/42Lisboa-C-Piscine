/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:54:06 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:54:09 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_min(int tl, int l, int t)
{
	if (tl <= l && tl <= t)
		return (tl);
	if (l <= tl && l <= t)
		return (l);
	if (t <= tl && t <= l)
		return (t);
	return (-1);
}

int		**ft_find_solution(int **arr, int row_len)
{
	int i;
	int j;

	i = 1;
	while (arr[i] != 0)
	{
		j = 1;
		while (j < row_len)
		{
			if (arr[i][j] != 0)
				arr[i][j] = ft_min(arr[i - 1][j - 1],
				arr[i][j - 1], arr[i - 1][j]) + 1;
			j++;
		}
		i++;
	}
	return (arr);
}

int		*ft_bsq(int **arr, int row_len)
{
	int i;
	int j;
	int *solved;

	i = 0;
	if (!(solved = malloc(sizeof(int) * 3)))
		return (0);
	solved[2] = 0;
	while (arr[i] != 0)
	{
		j = 0;
		while (j < row_len)
		{
			if (arr[i][j] > solved[2])
			{
				solved[0] = i;
				solved[1] = j;
				solved[2] = arr[i][j];
			}
			j++;
		}
		i++;
	}
	return (solved);
}
