/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:47:03 by melkess           #+#    #+#             */
/*   Updated: 2024/11/30 16:21:27 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup( char *s1, int aid)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	s = (char *)malloc(i +1);
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	if (aid)
		free(s1);
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	char	*head;
	char	*hold;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2, 0));
	if (!s2)
	{
		return (ft_strdup(s1, 1));
	}
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +2);
	if (!newstr)
		return (NULL);
	head = newstr;
	hold = s1;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2 && *s2 != '\n')
		*newstr++ = *s2++;
	if (*s2 == '\n')
		*newstr++ = '\n';
	*newstr = '\0';
	free(hold);
	return (head);
}

int	is_there_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (i < BUFFER_SIZE && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (0);
	return (1);
}
