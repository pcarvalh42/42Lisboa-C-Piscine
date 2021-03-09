/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:14:18 by pcarvalh          #+#    #+#             */
/*   Updated: 2020/12/08 14:38:53 by pcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned	int	ft_strlen(char *src)
{
	unsigned int s;

	s = 0;
	while (src[s] != '\0')
		s++;
	return (s);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int sdest;
	unsigned int ssrc;
	unsigned int i;

	sdest = ft_strlen(dest);
	if (sdest > size)
		sdest = size;
	ssrc = ft_strlen(src);
	i = 0;
	while (src[i] && (sdest + i + 1) < size)
	{
		dest[sdest + i] = src[i];
		i++;
	}
	if (sdest < size)
		dest[sdest + i] = '\0';
	return (sdest + ssrc);
}
