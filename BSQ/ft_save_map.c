/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:55:31 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:55:39 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_save_map(char *fullmap)
{
	t_fline	fline;
	int		**arr;
	int		*solution;
	int		checker;
	char	*fieldmap;

	checker = ft_first_line(fullmap, ft_fl_size(fullmap), &fline);
	if (fullmap == 0 || checker == 0)
	{
		ft_map_error();
		return (1);
	}
	fieldmap = ft_map_wo_fline(fullmap, ft_fl_size(fullmap));
	if (ft_map_is_valid(fieldmap, &fline) != 0)
	{
		free(fieldmap);
		return (1);
	}
	arr = ft_map_to_arr(fieldmap, fline.nbr_lines, fline.empty);
	solution = ft_bsq(arr, ft_row_len(fieldmap));
	ft_print_solution(arr, solution, ft_row_len(fieldmap), &fline);
	ft_sanitize(arr);
	free(arr);
	free(fieldmap);
	return (0);
}

void	ft_file_input(char *filename)
{
	char	*fullmap;

	fullmap = ft_file_to_str(filename);
	if (fullmap)
	{
		ft_save_map(fullmap);
		free(fullmap);
	}
	else
		ft_map_error();
}
