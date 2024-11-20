/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:00:30 by melkess           #+#    #+#             */
/*   Updated: 2024/11/18 13:50:14 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			totalnumberofbytes;
	size_t			i;

	totalnumberofbytes = count * size;
	if (count && size && totalnumberofbytes / count != size)
		return (NULL);
	ptr = malloc (totalnumberofbytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < totalnumberofbytes)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
