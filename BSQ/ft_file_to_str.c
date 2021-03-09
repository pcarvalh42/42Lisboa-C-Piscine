/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:53:52 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/16 11:53:59 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_file_size(char *filename)
{
	int		fd;
	int		size;
	char	c;

	fd = open(filename, O_RDONLY);
	size = 0;
	if (fd < 0)
		return (0);
	while ((read(fd, &c, 1)) > 0)
		size++;
	close(fd);
	return (size);
}

char	*ft_file_to_str(char *filename)
{
	int		fd;
	int		size;
	char	*fullmap;

	size = ft_file_size(filename);
	fullmap = malloc(size + 1);
	if (!fullmap || size == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(fullmap);
		return (0);
	}
	if (read(fd, fullmap, size) < 0)
	{
		close(fd);
		return (0);
	}
	fullmap[size] = '\0';
	return (fullmap);
}

char	*ft_map_wo_fline(char *fullmap, int fline_size)
{
	char	*fieldmap;
	int		i;
	int		j;

	fieldmap = malloc(ft_strlen(fullmap) - fline_size + 1);
	if (!fieldmap)
		return (0);
	i = 0;
	j = 0;
	while (i < fline_size)
		i++;
	i++;
	while (fullmap[i] != '\0')
	{
		fieldmap[j++] = fullmap[i++];
	}
	fieldmap[j] = '\0';
	return (fieldmap);
}
