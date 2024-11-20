/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 07:51:00 by melkess           #+#    #+#             */
/*   Updated: 2024/11/19 14:11:24 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n, int *isnegative)
{
	int	i;

	*isnegative = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*isnegative = 1;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		isnegative;

	len = ft_counter(n, &isnegative);
	str = (char *)malloc(len +1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
	{
		n /= 10;
		str[--len] = '8';
	}
	if (isnegative)
		n *= -1;
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (isnegative)
		str[0] = '-';
	return (str);
}
