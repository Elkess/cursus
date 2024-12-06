/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkess <melkess@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:46:59 by melkess           #+#    #+#             */
/*   Updated: 2024/12/06 15:17:53 by melkess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(int fd, char	*holder)
{
	int		reads;
	char	*buff;
	char	*temp;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (free(holder), holder = NULL, NULL);
	reads = 1;
	while (reads && !ft_strchr(holder, '\n'))
	{
		reads = read(fd, buff, BUFFER_SIZE);
		if (reads < 0)
			return (free(buff), free(holder), NULL);
		buff[reads] = '\0';
		temp = holder;
		holder = ft_strjoin(holder, buff);
		free(temp);
	}
	free(buff);
	return (holder);
}

static char	*filter_line(char *holder)
{
	int	i;

	if (*holder == '\0')
		return (NULL);
	i = 0;
	while (holder[i] != '\n' && holder[i] != '\0')
		i++;
	return (ft_substr(holder, 0, i +1));
}

static char	*ft_remainder(char *holder)
{
	char	*updated_holder;
	int		start;
	int		i;

	start = 0;
	while (holder[start] && holder[start] != '\n')
		start++;
	if (!holder[start])
		return (free(holder), holder = NULL, NULL);
	start++;
	i = 0;
	while (holder[start + i])
		i++;
	updated_holder = (char *)malloc((i + 1) * sizeof(char));
	if (!updated_holder)
		return (free(holder), holder = NULL, NULL);
	i = 0;
	while (holder[start])
		updated_holder[i++] = holder[start++];
	updated_holder[i] = '\0';
	free(holder);
	return (updated_holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	line = NULL;
	holder = extract_line(fd, holder);
	if (!holder)
		return (NULL);
	line = filter_line(holder);
	if (!line)
		return (free(holder), holder = NULL, NULL);
	holder = ft_remainder(holder);
	return (line);
}

/*
void ff()
{
	system("leaks a.out");
}
int main(void)
{
	// atexit(ff);
	int fd ;
	char *s ;
	fd = open("../files/file2.txt", O_RDWR);

	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	return 0;
}

*/
