/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:55:51 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:55:54 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_stdin(void)
{
	char	buff[BUFF_SIZE];
	int		result;
	int		i;

	i = 0;
	while ((result = read(0, &buff[i], 1)) > 0)
	{
		if (i > BUFF_SIZE - 2 || result == 0)
		{
			ft_map_error();
			return ;
		}
		if (buff[i++] == '\n')
			continue;
	}
	buff[i] = '\0';
	ft_save_map(buff);
}
