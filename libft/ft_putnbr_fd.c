/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:33:31 by melkess           #+#    #+#             */
/*   Updated: 2024/11/19 14:06:34 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	arr[10];
	int	i;

	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n = 147483648;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (n)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	while (i)
		ft_putchar_fd(arr[--i] +48, fd);
}
