/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:59:02 by melkess           #+#    #+#             */
/*   Updated: 2024/11/17 14:09:57 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ls;
	size_t	ld;
	size_t	i;

	ls = 0;
	ld = 0;
	i = 0;
	while (src[ls])
		ls++;
	if (dstsize == 0)
		return (ls);
	while (dst[ld] && ld < dstsize)
		ld++;
	if (dstsize == ld)
		return (ls + dstsize);
	while (src[i] && dstsize -1 > ld + i)
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ld + ls);
}
