/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:14:01 by pcarvalh          #+#    #+#             */
/*   Updated: 2020/11/30 16:24:17 by pcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	if (nb == 0)
	{
		return (dest);
	}
	else
	{
		while (i2 < nb && src[i2] != '\0')
		{
			dest[i] = src[i2];
			i2++;
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}
