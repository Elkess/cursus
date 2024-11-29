/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:46:59 by melkess           #+#    #+#             */
/*   Updated: 2024/11/29 21:52:41 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
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
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*head;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!newstr)
		return (NULL);
	head = newstr;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2 && *s2 != '\n')
		*newstr++ = *s2++;
	*newstr = '\0';
	return (head);
}

int	is_there_newline(char *s)
{
	int i;
	i = 0;
	if (!s)
		return (0);
	while (i < BUFFER_SIZE && s[i] != '\n')
		i++;
	if (s[i] == '\n' || s[i] == '\0')
	{
		puts("here");
		return (0);
	}
	else
	{
		puts("there");
		return (1);
	}
}

char *get_next_line(int fd)
{
	int running;
	int i;
	static char *temp;
	char *tempt;

	running = 1;
	i = 0;
	char *line = malloc(BUFFER_SIZE);
	while (running)
	{
		read(fd, line, BUFFER_SIZE);
		running = is_there_newline(line);
		temp = ft_strjoin(temp, line);
		tempt = temp;
		if (running == 0)
		{
			while (line[i] != '\n')
				i++;
			temp = line + i +1;
		}
	}
	return (tempt);
}

int main(void)
{
	int fd , i;
	// char *s ;
	fd = open("file.txt", O_CREAT | O_RDWR , 0777);
	i = 0;

		printf("%s\n",  get_next_line(fd));
		printf("%s\n",  get_next_line(fd));
		printf("%s\n",  get_next_line(fd));
		

		// s = get_next_line(fd);
		// printf("%s\n", s);
		// s = get_next_line(fd);
		// printf("%s\n", s);
		// s = get_next_line(fd);
		// printf("%s\n", s);
		// s = get_next_line(fd);
		// printf("%s\n", s);
	return 0;
}

