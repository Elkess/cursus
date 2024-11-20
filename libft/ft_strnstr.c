/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:09:51 by melkess           #+#    #+#             */
/*   Updated: 2024/11/19 13:48:58 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (n[0] == '\0')
		return ((char *)hs);
	i = 0;
	while (i < len && hs[i])
	{
		j = 0;
		while (i + j < len && hs[i + j] == n[j])
		{
			j++;
			if (n[j] == '\0')
				return ((char *)(hs + i));
		}
		i++;
	}
	return (NULL);
}
