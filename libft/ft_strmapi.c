/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:14:24 by melkess           #+#    #+#             */
/*   Updated: 2024/11/19 10:52:31 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mappedstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	mappedstr = (char *) malloc(ft_strlen(s) +1);
	if (!mappedstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mappedstr[i] = f(i, s[i]);
		i++;
	}
	mappedstr[i] = '\0';
	return (mappedstr);
}
